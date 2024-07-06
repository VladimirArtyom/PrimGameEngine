#pragma once

/* Suivant les conventions de Rust, car c'est trop long en c 
   (Following rust conventions, because it's too long for c)
*/ 

// Unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

//floating point types
typedef float f32;
typedef double f64;

//boolean types
typedef int b32;
typedef char b8;

// S'assurer que tous les types ont la bonne taille
// Ensure all types are the right size
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#endif

STATIC_ASSERT(sizeof(u8) == 1, "u8 must be 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "u16 must be 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "u32 must be 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "u64 must be 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "i8 must be 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "i16 must be 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "i32 must be 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "i64 must be 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "f32 must be 4 bytes"); 
STATIC_ASSERT(sizeof(f64) == 8, "f64 must be 8 bytes");

#define TRUE 1
#define FALSE 0


// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#define KPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define KPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define KPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// Catch anything not caught by the above.
#define KPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
// Posix
#define KPLATFORM_POSIX 1
#elif __APPLE__
// Apple platforms
#define KPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#define KPLATFORM_IOS 1
#define KPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define KPLATFORM_IOS 1
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unknown platform!"
#endif

#ifdef PREXPORT
// Exports

/*
Exporting and importing symbols in C (and C++)
are techniques used when working with dynamic-link libraries (DLLs) or shared libraries. So that you're able to use modules
or libraries on a program

__declspec(dllexport): Specific to Microsoft's Visual C++ compiler (_MSC_VER),
 this indicates that the function or data should be exported from a DLL.

__attribute__((visibility("default"))): Used for GCC and Clang compilers,
 this specifies that the symbol should be visible outside the shared object or dynamic library (default visibility).

__declspec(dllimport): Also specific to Visual C++ (_MSC_VER),
  this indicates that the function or data should be imported from a DLL.

*/
#ifdef _MSC_VER
#define PRAPI __declspec(dllexport)
#else
#define PRAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define PRAPI __declspec(dllimport)
#else
#define PRAPI
#endif
#endif



