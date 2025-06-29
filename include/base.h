#ifndef BASE_H
#define BASE_H

#include <stdint.h>
#include <time.h>
#include <stdio.h>

// defining type aliases
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef float f32;
typedef double f64;

/*
 * defining a logging macro that logs a string when called in debug. 
 * otherwise it does nothing in release mode when compiled using the cmake file
 */
#ifdef NDEBUG
#define LOG(...)
#else
#define LOG(...) { \
    time_t current_time = time(NULL); \
    char* stime = ctime(&current_time); \
    if (stime) { \
        stime[strlen(stime) - 1] = '\0'; /* remove \n */ \
        printf("%s | ", stime); \
        printf(__VA_ARGS__); \
    } \
}
#endif

#endif
