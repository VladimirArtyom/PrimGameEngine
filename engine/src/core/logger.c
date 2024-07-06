#include "logger.h"
#include "defines.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

b8 initialize_logging()
{
    return TRUE;
}

void shutdown_logging() {

}

void log_output(log_level level, const char *message, ...) {
    const char* level_names[] = {"[FATAL]:", "[ERROR]:", "[WARN]:", "[INFO]:", "[DEBUG]:", "[TRACE]:"};

    char out_message[32000];
    memset(out_message, 0, sizeof(out_message));

    // Ce bloc est destine a la gestion des parametres variadiques
    // This block is for handling variadic parameters 
    __builtin_va_list args;
    va_start(args, message); // set args with message and variadic parameters
    vsnprintf(out_message, sizeof(out_message), message, args);
    va_end(args); // clean args variable

    char output[32000];
    sprintf(output, "%s %s \n", level_names[level], out_message);

    printf("%s", output);

}