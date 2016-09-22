
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_OS_H_INCLUDED_
#define _NGX_OS_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>

/*
 * Windows 7                 6.1  (601)
 * Windows Server 2008 R2    6.1  (601)
 * Windows Server 2008       6.0  (600)
 * Windows Vista             6.0  (600)
 * Windows Server 2003 R2    5.2  (502)
 * Windows Server 2003       5.2  (502)
 * Windows XP                5.1  (501)
 * Windows 2000              5.0  (500)
 * Windows Me                4.90 (490)
 * Windows 98                4.10 (410)
 * Windows NT 4.0            4.0  (400)
 * Windows 95                4.0  (400)
 * Windows CE
 */

/*
 * AcceptEx,TransmitFile:
 *     NT,2000,XP,2003,Vista,2008
 * ConnectEx,DisconnectEx,TransmitPackets:
 *     XP,Vista,2003,2008
 * GetAcceptExSockaddrs:
 *     95,98,Me,NT,2000,XP,2003,Vista,2008
 * GetQueuedCompletionStatusEx:
 *     Vista,2008
 */


#define NGX_WIN32_VER_601  260100
#define NGX_WIN32_VER_600  260000
#define NGX_WIN32_VER_502  250200
#define NGX_WIN32_VER_501  250100
#define NGX_WIN32_VER_500  250000
#define NGX_WIN32_VER_400  240000

#define NGX_IO_SENDFILE    1


typedef ssize_t (*ngx_recv_pt)(ngx_connection_t *c, u_char *buf, size_t size);
typedef ssize_t (*ngx_recv_chain_pt)(ngx_connection_t *c, ngx_chain_t *in,
    off_t limit);
typedef ssize_t (*ngx_send_pt)(ngx_connection_t *c, u_char *buf, size_t size);
typedef ngx_chain_t *(*ngx_send_chain_pt)(ngx_connection_t *c, ngx_chain_t *in,
    off_t limit);

typedef struct {
    ngx_recv_pt        recv;
    ngx_recv_chain_pt  recv_chain;
    ngx_recv_pt        udp_recv;
    ngx_send_pt        send;
	ngx_send_pt        udp_send;
    ngx_send_chain_pt  send_chain;
    ngx_uint_t         flags;
} ngx_os_io_t;


typedef BOOL (WINAPI *LPFN_GETQUEUEDCOMPLETIONSTATUSEX)(HANDLE CompletionPort,
    LPOVERLAPPED_ENTRY lpCompletionPortEntries, ULONG ulCount,
    PULONG ulNumEntriesRemoved, DWORD dwMilliseconds, BOOL fAlertable);

typedef BOOL (WINAPI *LPFN_SETFILECOMPLETIONNOTIFICATIONMODES)(
    HANDLE FileHandle, UCHAR Flags);


#ifndef FILE_SKIP_COMPLETION_PORT_ON_SUCCESS
#  define FILE_SKIP_COMPLETION_PORT_ON_SUCCESS           0x1
#endif

#ifndef FILE_SKIP_SET_EVENT_ON_HANDLE
#  define FILE_SKIP_SET_EVENT_ON_HANDLE                  0x2
#endif



ngx_int_t ngx_os_init(ngx_log_t *log);
void ngx_os_status(ngx_log_t *log);
ngx_int_t ngx_os_signal_process(ngx_cycle_t *cycle, char *sig, ngx_pid_t pid);

ssize_t ngx_wsarecv(ngx_connection_t *c, u_char *buf, size_t size);
ssize_t ngx_wsarecv_chain(ngx_connection_t *c, ngx_chain_t *chain, off_t limit);
ssize_t ngx_udp_wsarecv(ngx_connection_t *c, u_char *buf, size_t size);

ssize_t ngx_overlapped_wsarecv(ngx_connection_t *c, u_char *buf, size_t size);
ssize_t ngx_overlapped_wsarecv_chain(ngx_connection_t *c, ngx_chain_t *chain, 
                                     off_t limit);
ssize_t ngx_udp_overlapped_wsarecv(ngx_connection_t *c, u_char *buf,
                                   size_t size);

ssize_t ngx_wsasend(ngx_connection_t *c, u_char *buf, size_t size);
ssize_t ngx_udp_wsasend(ngx_connection_t *c, u_char *buf, size_t size);
ssize_t ngx_overlapped_wsasend(ngx_connection_t *c, u_char *buf, size_t size);
ngx_chain_t *ngx_wsasend_chain(ngx_connection_t *c, ngx_chain_t *in,
    off_t limit);
ngx_chain_t *ngx_overlapped_wsasend_chain(ngx_connection_t *c, ngx_chain_t *in,
    off_t limit);

void ngx_cdecl ngx_event_log(ngx_err_t err, const char *fmt, ...);


extern ngx_os_io_t  ngx_os_io;
extern ngx_uint_t   ngx_ncpu;
extern ngx_uint_t   ngx_max_wsabufs;
extern ngx_int_t    ngx_max_sockets;
extern ngx_uint_t   ngx_inherited_nonblocking;
extern ngx_uint_t   ngx_tcp_nodelay_and_tcp_nopush;
extern ngx_uint_t   ngx_win32_version;
extern char         ngx_unique[];

extern LPFN_GETQUEUEDCOMPLETIONSTATUSEX         ngx_get_queued_completion_status_ex;
extern LPFN_SETFILECOMPLETIONNOTIFICATIONMODES  ngx_set_file_completion_notification_modes;


#endif /* _NGX_OS_H_INCLUDED_ */
