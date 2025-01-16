#include "config.h"

// define macros and tools useful for testing

#ifdef TESTING
    #define assert(bool_expression) ((void)0) /* Define it as a no-op */
#else
#define assert(bool_expression) \
    if (!(bool_expression)) bad_assertion(__FILE__,__LINE__, #bool_expression);
#endif
