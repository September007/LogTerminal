#pragma once

#include <symbols.h>
#ifdef CONNECTION_PROTOCAL_EXPORT
#    define CP_API API_DESC_EXPORT
#else
#    define CP_API API_DESC_IMPORT
#endif