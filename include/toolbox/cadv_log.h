#include <stdio.h>
#include <stdarg.h>

#define LOGGER(fmt, ...)          \
    do                            \
    {                             \
        printf(fmt, __VA_ARGS__); \
    } while (0)

static inline void log_info(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, fmt, args);
    va_end(args);
}

#define LOG_INFO(fmt, ...)          \
    do                              \
    {                               \
        log_info(fmt, __VA_ARGS__); \
    } while (0)
    