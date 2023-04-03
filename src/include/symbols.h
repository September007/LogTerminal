#pragma once

#if defined(_WIN32)
#    define API_DESC_EXPORT __declspec(dllexport)
#    define API_DESC_IMPORT __declspec(dllimport)
#elif defined(__GNUC__) && defined(API_DESC_EXPORT_BUILD)
#    define API_DESC_EXPORT __attribute__((visibility("default")))
#    define API_DESC_IMPORT
#endif

/* using like follwing */

// #if defined(LIBXXX_EXPORT)
// #    define LIBXXX_API_DESC API_DESC_EXPORT
// #else
// #    define LIBXXX_API_DESC API_DESC_IMPORT
// #endif

// #define LIBXXX_API_VAR extern LIBXXX_API_DESC
// #define LIBXXX_API_CLS LIBXXX_API_DESC
// #define LIBXXX_API     LIBXXX_API_DESC