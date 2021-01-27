#pragma once
#if defined(_MSC_VER)
// Windows
    #if defined(TEMPLATE_LIB_IMPORT)
        #define EXPORT_TEMPLATE_LIB __declspec(dllimport)
    #else
        #define EXPORT_TEMPLATE_LIB __declspec(dllexport)
    #endif
#elif defined(__GNUC__)
//  GCC
    #define EXPORT_TEMPLATE_LIB __attribute__((visibility("default")))
#else
    //  do nothing and hope for the best?
    #define EXPORT_TEMPLATE_LIB
    #pragma warning Unknown dynamic link import/export semantics.
#endif