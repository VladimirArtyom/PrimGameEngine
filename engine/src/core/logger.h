#pragma once

#include "defines.h"

// Defines def
// Ces journaux peuvent etre ajustes car ils sont destinés au debogage et non a la production.
// These log can be tuned because its for debugging purposes not for production
#define LOG_WARN_ENABLED 0
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1


// Desactiver le debogage et le trace pour les builds de production
// Disable debug and trace logging for production builds
#if PRRELEASE == 1
    #define LOG_DEBUG_ENABLED 0 
    #define LOG_TRACE_ENABLED 0 
#endif

typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;


b8 initialize_logging();
void shutdown_logging();

PRAPI void log_output(log_level level, const char* message, ...);
// Using Macros to avoid duplicated code and to make it more readable.
// __VA_ARGS__ is a macro for variadic arguments.

#ifndef PRFATAL
    #define PRFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);
#endif

#ifndef PRERROR
    #define PRERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
    #define PRWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else 
    #define PRWARN(message, ...) do {} while(0)
#endif

#if LOG_INFO_ENABLED == 1
    #define PRINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
    #define PRINFO(message, ...) do {} while(0)
#endif

#if LOG_DEBUG_ENABLED == 1
    #define PRDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else 
    #define PRDEBUG(message, ...) do {} while(0)
#endif

#if LOG_TRACE_ENABLED == 1
    #define PRTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else 
    #define PRTRACE(message, ...) do {} while(0)
#endif






