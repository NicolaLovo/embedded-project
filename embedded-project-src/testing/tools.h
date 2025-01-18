#include "config.h"

// define macros and tools useful for testing

#ifndef TESTING
    #define assert(bool_expression) ((void)0) /* Define it as a no-op */
#else

void bad_assertion(const char *file, int line, const char *expression) {
    printf("Assertion failed: (%s), file %s, line %d\n", expression, file, line);
    exit(1);
}

#define assert(bool_expression) \
    if (!(bool_expression)) bad_assertion(__FILE__,__LINE__, #bool_expression);
#endif
