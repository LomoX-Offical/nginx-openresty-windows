#ifndef _CONFIG_WIN32_H
#define _CONFIG_WIN32_H

#if     defined(WIN32)
#	ifndef FOUND_C99_ISXX
#		undef  isnan
#		undef  isinf
#	endif
#endif
#if     !defined(isnan) && !defined(HAVE_ISNAN) && !defined(HAVE_C99_ISNAN)
#	define isnan(val)      (0)
#endif
#if     !defined(isinf) && !defined(HAVE_ISINF) && !defined(HAVE_C99_ISINF)
#	define isinf(val)      (0)
#endif

#if !defined strcasecmp
#define strcasecmp _stricmp
#endif

#if !defined strncasecmp
#define strncasecmp  _strnicmp 
#endif


#if !defined snprintf
#define snprintf _snprintf
#endif

#if defined(WIN32) && !defined(__cplusplus)
#define inline __inline
#endif

#endif  /* _CONFIG_WIN32_H */
