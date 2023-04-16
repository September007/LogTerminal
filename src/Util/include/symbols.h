#pragma once

#if defined(_WIN32)
#    define API_DESC_EXPORT __declspec(dllexport)
#    define API_DESC_IMPORT __declspec(dllimport)
#elif defined(__GNUC__) //&& defined(API_DESC_EXPORT_BUILD)
#    define API_DESC_EXPORT __attribute__((visibility("default")))
#    define API_DESC_IMPORT
#endif


/* the rest is private for log util  */
#if defined(UTIL_EXPORT)
#    define LTU_API_DESC API_DESC_EXPORT
#else
#    define LTU_API_DESC API_DESC_IMPORT
#endif

#define LTU_API_VAR extern LTU_API_DESC
#define LTU_API_CLS LTU_API_DESC
#define LTU_API     LTU_API_DESC
