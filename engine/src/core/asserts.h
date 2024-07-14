#pragma once

#include "defines.h"

#define PRASSERTIONS_ENABLED

#ifdef PRASSERTIONS_ENABLED
// If the code is compiled by the microsoft visual C++ compiler
//
#if _MSC_VER
    #include <intrin.h>
    #define debugBreak() __debugbreak()
#else 
// Others
    #define debugBreak() __builtin_trap()
#endif


PRAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

// All Assertions
#define PRASSERT(expression) {if (expression) {} else report_assertion_failure(#expression, "", __FILE__, __LINE__); debugBreak();}

#define PRASSERT_MSG(expression , msg) {if(expression) {} else report_assertion_failure(#expression, msg, __FILE__, __LINE__); debugBreak();}

#ifdef _DEBUG
    #define PRASSERT_DEBUG(expression) {if(expression) {} else report_assertion_failure(#expression, "", __FILE__, __LINE__); debugBreak();}
#else 
    #define PRASSERT_DEBUG(expr)
#endif

#else 
    #define PRASSERT(expressionq)
    #define PRASSERT_MSG(expression, msg)
    #define PRASSERT_DEBUG(expr)
#endif