#ifndef NIGHT_VM_EXPORT_H
#define NIGHT_VM_EXPORT_H

#ifdef NIGHT_WIN
    #ifdef NIGHT_VM_BUILD
        #define NIGHT_VM_API __declspec(dllexport)
    #else
        #define NIGHT_VM_API __declspec(dllimport)
    #endif

#else
    #define NIGHT_VM_API
#endif

#endif