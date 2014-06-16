#ifndef DEFINE_H
#define DEFINE_H

#include "CompilerDefs.h"

#include <ace/Basic_Types.h>
#include <ace/ACE_export.h>

#include <cstddef>

#define LITTLEENDIAN 0
#define BIGENDIAN    1

#if !defined(ENDIAN)
#  if defined (ACE_BIG_ENDIAN)
#    define ENDIAN BIGENDIAN
#  else //ACE_BYTE_ORDER != ACE_BIG_ENDIAN
#    define ENDIAN LITTLEENDIAN
#  endif //ACE_BYTE_ORDER
#endif //ENDIAN

#if PLATFORM == PLATFORM_WINDOWS
#  define PATH_MAX MAX_PATH
#  ifndef DECLSPEC_NORETURN
#    define DECLSPEC_NORETURN __declspec(noreturn)
#  endif //DECLSPEC_NORETURN
#  ifndef DECLSPEC_DEPRECATED
#    define DECLSPEC_DEPRECATED __declspec(deprecated)
#  endif //DECLSPEC_DEPRECATED
#else //PLATFORM != PLATFORM_WINDOWS
#  define PATH_MAX PATH_MAX
#  define DECLSPEC_NORETURN
#  define DECLSPEC_DEPRECATED
#endif //PLATFORM

#if !defined(COREDEBUG)
#  define INLINE inline
#else //COREDEBUG
#  if !defined(DEBUG)
#    define DEBUG
#  endif //DEBUG
#  define INLINE
#endif //!COREDEBUG

#if COMPILER == COMPILER_GNU
#  define ATTR_NORETURN __attribute__((noreturn))
#  define ATTR_PRINTF(F, V) __attribute__ ((format (printf, F, V)))
#  define ATTR_DEPRECATED __attribute__((deprecated))
#else //COMPILER != COMPILER_GNU
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F, V)
#  define ATTR_DEPRECATED
#endif //COMPILER == COMPILER_GNU

#define UI64FMTD ACE_UINT64_FORMAT_SPECIFIER
#define UI64LIT(N) ACE_UINT64_LITERAL(N)

#define SI64FMTD ACE_INT64_FORMAT_SPECIFIER
#define SI64LIT(N) ACE_INT64_LITERAL(N)

#define SIZEFMTD ACE_SIZE_T_FORMAT_SPECIFIER

typedef ACE_INT64 int64;
typedef ACE_INT32 int32;
typedef ACE_INT16 int16;
typedef ACE_INT8 int8;
typedef ACE_UINT64 uint64;
typedef ACE_UINT32 uint32;
typedef ACE_UINT16 uint16;
typedef ACE_UINT8 uint8;

#endif //DEFINE_H
