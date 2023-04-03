#pragma once
#include <cstdint>

#include <symbols.h>
#ifdef ARITHCODEC_EXPORT
#    define AC_API API_DESC_EXPORT
#else
#    define AC_API API_DESC_IMPORT
#endif

struct AC_Data
{
    uint8_t *begin = 0;
    int size = 0;
};

/* be sure data is not released when Encode processing  */
/* return.size>=0 if success */
AC_API AC_Data Encode(AC_Data data);

/* be sure data is not released when Encode processing  */
/* return.size>=0 if success */
AC_API AC_Data Decode(AC_Data data );