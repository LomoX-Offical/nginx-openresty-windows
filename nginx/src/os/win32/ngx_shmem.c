
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#include <ngx_config.h>
#include <ngx_core.h>

typedef	u_char *	caddr_t;
#define page_const ((ptrdiff_t) 65536)
#define pround(n) ((ptrdiff_t)((((n) / page_const) + 1) * page_const))
#define off_addr(base_addr, size)	((u_char *)((caddr_t) base_addr + pround(size)))

u_char* _get_address(uint64_t size) {
    static u_char* nginx_hmodule = NULL;
    u_char* retval = NULL;

	if (nginx_hmodule == NULL) {

#ifdef _WIN64
    nginx_hmodule = (u_char*)0x200000000; //GetModuleHandle(NULL);
#else
    nginx_hmodule = (u_char*)0x20000000; //GetModuleHandle(NULL);
#endif
	}
    
    retval = nginx_hmodule;
	nginx_hmodule = off_addr(nginx_hmodule, size);

	return retval;
}

ngx_int_t
ngx_shm_alloc(ngx_shm_t *shm)
{
    u_char    *name;
    uint64_t   size;
	u_char    *reserved_mem;
	u_char    *base_address;

    name = ngx_alloc(shm->name.len + 9 + NGX_INT32_LEN, shm->log); // 9 = "Global\\" + "_" + \0
    if (name == NULL) {
        return NGX_ERROR;
    }

    (void) ngx_sprintf(name, "Global\\%V_%s%Z", &shm->name, ngx_unique);

    ngx_set_errno(0);

    size = shm->size;

    ngx_log_error(NGX_LOG_NOTICE, shm->log, ngx_errno, "Shared memory name is [%s]", name);
    shm->handle = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
                                    (u_long) (size >> 32),
                                    (u_long) (size & 0xffffffff),
                                    (char *) name);

    if (shm->handle == NULL) {
        ngx_log_error(NGX_LOG_EMERG, shm->log, ngx_errno,
                      "CreateFileMapping(%uz, %s) failed",
                      shm->size, name);
        ngx_free(name);

        return NGX_ERROR;
    }

    ngx_free(name);

    if (ngx_errno == ERROR_ALREADY_EXISTS) {
        shm->exists = 1;
    }

	base_address = _get_address(size);
	reserved_mem = (u_char*)VirtualAlloc(
		base_address,
		shm->size,
		MEM_RESERVE,
		PAGE_NOACCESS);
	VirtualFree(reserved_mem, 0, MEM_RELEASE);
	ngx_log_error(NGX_LOG_NOTICE, shm->log, ngx_errno, "VirtualAlloc MEM_RELEASE: %p, base_address: %p", reserved_mem, base_address);

	shm->addr = MapViewOfFileEx(shm->handle, FILE_MAP_WRITE, 0, 0, 0, reserved_mem);

    if (shm->addr != NULL) {
		ngx_log_error(NGX_LOG_NOTICE, shm->log, ngx_errno,
			"MapViewOfFile(%uz) of file mapping \"%V\" success: %p",
			shm->size, &shm->name, shm->addr);
		return NGX_OK;
    }

    ngx_log_error(NGX_LOG_EMERG, shm->log, ngx_errno,
                  "MapViewOfFile(%uz) of file mapping \"%V\" failed",
                  shm->size, &shm->name);

    if (CloseHandle(shm->handle) == 0) {
        ngx_log_error(NGX_LOG_EMERG, shm->log, ngx_errno,
                      "CloseHandle() of file mapping \"%V\" failed",
                      &shm->name);
    }

    return NGX_ERROR;
}
/*
allocate:
size = shm->size;
shm->addr = ngx_alloc(size, shm->log);

if (shm->addr != NULL) {
	return NGX_OK;
}
return NGX_ERROR;


release:
ngx_free(shm->addr);

*/


void
ngx_shm_free(ngx_shm_t *shm)
{
    if (UnmapViewOfFile(shm->addr) == 0) {
        ngx_log_error(NGX_LOG_ALERT, shm->log, ngx_errno,
                      "UnmapViewOfFile(%p) of file mapping \"%V\" failed",
                      shm->addr, &shm->name);
    }

    if (CloseHandle(shm->handle) == 0) {
        ngx_log_error(NGX_LOG_ALERT, shm->log, ngx_errno,
                      "CloseHandle() of file mapping \"%V\" failed",
                      &shm->name);
    }



}
