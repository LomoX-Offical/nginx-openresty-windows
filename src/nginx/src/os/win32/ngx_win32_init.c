
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>
#include <nginx.h>


ngx_uint_t  ngx_win32_version;
ngx_uint_t  ngx_ncpu;
ngx_uint_t  ngx_max_wsabufs;
ngx_int_t   ngx_max_sockets;
ngx_uint_t  ngx_inherited_nonblocking = 1;
ngx_uint_t  ngx_tcp_nodelay_and_tcp_nopush;

char        ngx_unique[NGX_INT32_LEN + 1];


ngx_os_io_t ngx_os_io = {
    ngx_wsarecv,
    ngx_wsarecv_chain,
    ngx_udp_wsarecv,
    ngx_wsasend,
    ngx_udp_wsasend,
    ngx_wsasend_chain,
    0
};

typedef struct {
	WORD  wServicePackMinor;
	WORD  wSuiteMask;
	BYTE  wProductType;
} ngx_osviex_stub_t;


static u_int               is_osviex;
static OSVERSIONINFOEX     osvi;

/* Should these pointers be per protocol ? */
LPFN_ACCEPTEX                     ngx_acceptex;
LPFN_CONNECTEX                    ngx_connectex;
LPFN_DISCONNECTEX                 ngx_disconnectex;
LPFN_TRANSMITFILE                 ngx_transmitfile;
LPFN_TRANSMITPACKETS              ngx_transmitpackets;
LPFN_GETACCEPTEXSOCKADDRS         ngx_getacceptexsockaddrs;
LPFN_GETQUEUEDCOMPLETIONSTATUSEX  ngx_get_queued_completion_status_ex;


static struct {
	GUID          guid;
	u_long        glen;
	void        **func;
	u_long        flen;
	ngx_uint_t    win_ver;
	char         *func_name;
}  ngx_wefs[] = {

	{ WSAID_GETACCEPTEXSOCKADDRS,
	sizeof(GUID),
	(void **) &ngx_getacceptexsockaddrs,
	sizeof(ngx_getacceptexsockaddrs),
	NGX_WIN32_VER_400,
	"GetAcceptExSockaddrs" },

	{ WSAID_ACCEPTEX,
	sizeof(GUID),
	(void **) &ngx_acceptex,
	sizeof(ngx_acceptex),
	NGX_WIN32_VER_500,
	"AcceptEx" },

	{ WSAID_TRANSMITFILE,
	sizeof(GUID),
	(void **) &ngx_transmitfile,
	sizeof(ngx_transmitfile),
	NGX_WIN32_VER_500,
	"TransmitFile" },

	{ WSAID_CONNECTEX,
	sizeof(GUID),
	(void **) &ngx_connectex,
	sizeof(ngx_connectex),
	NGX_WIN32_VER_501,
	"ConnectEx" },

	{ WSAID_DISCONNECTEX,
	sizeof(GUID),
	(void **) &ngx_disconnectex,
	sizeof(ngx_disconnectex),
	NGX_WIN32_VER_501,
	"DisconnectEx" },

	{ WSAID_TRANSMITPACKETS,
	sizeof(GUID),
	(void **) &ngx_transmitpackets,
	sizeof(ngx_transmitpackets),
	NGX_WIN32_VER_501,
	"TransmitPackets" },

	{ {0,0,0,{0,0,0,0,0,0,0,0}}, 0, NULL, 0, 0, NULL }
};


ngx_int_t
ngx_os_init(ngx_log_t *log)
{
	void           *handle;
	long            rc;
	u_long          bytes;
	SOCKET          s;
	WSADATA         wsadata;
	in_port_t       port;
	ngx_err_t       err;
	ngx_uint_t      n;
	SOCKADDR_IN     sa;
	SYSTEM_INFO     si;


    /* current windows version */
    ngx_memzero(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

    is_osviex = GetVersionEx((OSVERSIONINFO *) &osvi);

    if (is_osviex == 0) {
        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
        if (GetVersionEx((OSVERSIONINFO *) &osvi) == 0) {
            ngx_log_error(NGX_LOG_EMERG, log, ngx_errno,
                          "GetVersionEx() failed");
            return NGX_ERROR;
        }
    }

#ifdef _MSC_VER
#pragma warning(default:4996)
#endif

    /*
     *  Windows 3.1 Win32s   0xxxxx
     *
     *  Windows 95           140000
     *  Windows 98           141000
     *  Windows ME           149000
     *  Windows NT 3.51      235100
     *  Windows NT 4.0       240000
     *  Windows NT 4.0 SP5   240050
     *  Windows 2000         250000
     *  Windows XP           250100
     *  Windows 2003         250200
     *  Windows Vista/2008   260000
     *
     *  Windows CE x.x       3xxxxx
     */

    ngx_win32_version = osvi.dwPlatformId * 100000
                        + osvi.dwMajorVersion * 10000
                        + osvi.dwMinorVersion * 100;

    if (is_osviex) {
        ngx_win32_version += osvi.wServicePackMajor * 10
                             + osvi.wServicePackMinor;
    }

    GetSystemInfo(&si);
    ngx_pagesize = si.dwPageSize;
    ngx_allocation_granularity = si.dwAllocationGranularity;
    ngx_ncpu = si.dwNumberOfProcessors;
    ngx_cacheline_size = NGX_CPU_CACHE_LINE;

    for (n = ngx_pagesize; n >>= 1; ngx_pagesize_shift++) { /* void */ }

    /* delete default "C" locale for _wcsicmp() */
    setlocale(LC_ALL, "");


	if (ngx_win32_version >= NGX_WIN32_VER_600) {
		handle = GetModuleHandle("kernel32.dll");
		if (handle == NULL) {
			ngx_log_error(NGX_LOG_ALERT, log, ngx_errno,
				"GetModuleHandle(\"kernel32.dll\") failed");
			return NGX_ERROR;
		}

		ngx_get_queued_completion_status_ex = (LPFN_GETQUEUEDCOMPLETIONSTATUSEX) GetProcAddress(handle,
			"GetQueuedCompletionStatusEx");
		if (ngx_get_queued_completion_status_ex == NULL) {
			ngx_log_error(NGX_LOG_ALERT, log, ngx_errno,
				"GetProcAddress(\"GetQueuedCompletionStatusEx\") failed");
			return NGX_ERROR;
		}
	}


	/* init Winsock */

	rc = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (rc != 0) {
		ngx_log_error(NGX_LOG_EMERG, log, rc, "WSAStartup() failed");
		return NGX_ERROR;

	} else if (LOBYTE(wsadata.wVersion) != 2
		|| HIBYTE(wsadata.wVersion) != 2)
	{
		ngx_log_error(NGX_LOG_EMERG, log, 0,
			"WinSock DLL doesn't supports V2.2");
		WSACleanup();
		return NGX_ERROR;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET) {
		ngx_log_error(NGX_LOG_EMERG, log, ngx_socket_errno,
			"socket() failed");
		WSACleanup();
		return NGX_ERROR;
	}

	if (ngx_win32_version < NGX_WIN_NT) {
		ngx_max_wsabufs = 16;
	} else {
		/* STUB: ngx_uint_t max */
		ngx_max_wsabufs = 1024 * 1024;
	}

	port = 0;

retry_bind:

	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	sa.sin_port = htons(port);

	if (bind(s, (SOCKADDR *) &sa, sizeof(SOCKADDR_IN)) == SOCKET_ERROR) {
		err = ngx_socket_errno;

		if (err == WSAEADDRINUSE) {
			ngx_log_error(NGX_LOG_ALERT, log, err, "bind() failed: %s:%u",
				inet_ntoa(sa.sin_addr), port);

			port++;
			goto retry_bind;
		}

		ngx_log_error(NGX_LOG_EMERG, log, err, "bind() failed");

		closesocket(s);
		WSACleanup();

		return NGX_ERROR;
	}

	if (listen(s, NGX_LISTEN_BACKLOG) == SOCKET_ERROR) {
		err = ngx_socket_errno;

		if (err == WSAEADDRINUSE) {
			ngx_log_error(NGX_LOG_ALERT, log, err, "listen() failed: %s:%u",
				inet_ntoa(sa.sin_addr), port);
			port++;
			goto retry_bind;
		}

		ngx_log_error(NGX_LOG_EMERG, log, err, "listen() failed");
		closesocket(s);
		WSACleanup();
		return NGX_ERROR;
	}

	for (n = 0; ngx_wefs[n].func; n++) {

		if (ngx_win32_version >= ngx_wefs[n].win_ver) {
			bytes = 0;

			if (WSAIoctl(s, SIO_GET_EXTENSION_FUNCTION_POINTER,
				&ngx_wefs[n].guid, ngx_wefs[n].glen,
				ngx_wefs[n].func, ngx_wefs[n].flen, &bytes, NULL, NULL)
				== SOCKET_ERROR)
			{
				err = ngx_socket_errno;

				if (err != WSAEINVAL && err != WSAEOPNOTSUPP) {
					ngx_log_error(NGX_LOG_EMERG, log, err,
						"WSAIoctl(%s) failed", ngx_wefs[n].func_name);
					closesocket(s);
					WSACleanup();
					return NGX_ERROR;
				}

				ngx_log_error(NGX_LOG_ALERT, log, err,
					"WSAIoctl: %s", ngx_wefs[n].func_name);

				continue;
			}

			ngx_log_debug1(NGX_LOG_DEBUG_CORE, log, 0,
				"WSAIoctl(%s) successfully", ngx_wefs[n].func_name);
		}
	}

	closesocket(s);



    if (GetEnvironmentVariable("ngx_unique", ngx_unique, NGX_INT32_LEN + 1)
        != 0)
    {
        ngx_process = NGX_PROCESS_WORKER;

    } else {
        err = ngx_errno;

        if (err != ERROR_ENVVAR_NOT_FOUND) {
            ngx_log_error(NGX_LOG_EMERG, log, err,
                          "GetEnvironmentVariable(\"ngx_unique\") failed");
            return NGX_ERROR;
        }

        ngx_sprintf((u_char *) ngx_unique, "%P%Z", ngx_pid);
    }

#if (NGX_HAVE_INHERITED_NONBLOCK)
	ngx_inherited_nonblocking = 1;
#else
	ngx_inherited_nonblocking = 0;
#endif

	srand((ngx_pid << 16) ^ (unsigned) ngx_time());

    return NGX_OK;
}


void
ngx_os_status(ngx_log_t *log)
{
    ngx_osviex_stub_t  *osviex_stub;

    ngx_log_error(NGX_LOG_NOTICE, log, 0, NGINX_VER_BUILD);

    if (is_osviex) {

        /*
         * the MSVC 6.0 SP2 defines wSuiteMask and wProductType
         * as WORD wReserved[2]
         */
        osviex_stub = (ngx_osviex_stub_t *) &osvi.wServicePackMinor;

        ngx_log_error(NGX_LOG_INFO, log, 0,
                      "OS: %ud build:%ud, \"%s\", suite:%Xd, type:%ud",
                      ngx_win32_version, osvi.dwBuildNumber, osvi.szCSDVersion,
                      osviex_stub->wSuiteMask, osviex_stub->wProductType);

    } else {
        if (osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS) {

            /* Win9x build */

            ngx_log_error(NGX_LOG_INFO, log, 0,
                          "OS: %u build:%ud.%ud.%ud, \"%s\"",
                          ngx_win32_version,
                          osvi.dwBuildNumber >> 24,
                          (osvi.dwBuildNumber >> 16) & 0xff,
                          osvi.dwBuildNumber & 0xffff,
                          osvi.szCSDVersion);

        } else {

            /*
             * VER_PLATFORM_WIN32_NT
             *
             * we do not currently support VER_PLATFORM_WIN32_CE
             * and we do not support VER_PLATFORM_WIN32s at all
             */

            ngx_log_error(NGX_LOG_INFO, log, 0, "OS: %ud build:%ud, \"%s\"",
                          ngx_win32_version, osvi.dwBuildNumber,
                          osvi.szCSDVersion);
        }
    }
}
