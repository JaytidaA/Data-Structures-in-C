/*
 * vector_utils.h
 * Defines utility functions and MACROS for Vectors defined in the
 * repository https://github.com/JaytidaA/coding-cpp
 * Author: https://github.com/JaytidaA/
 */

#ifndef JaytidaA_VEC_UTILS_H
#define JaytidaA_VEC_UTILS_H

#include "utils.h"
#include "vector/vector.h"

#if IS_PRINTABLE
#include <stdio.h>
#endif

#define print_vector(vec, type, fmt) do {              \
    if (IS_PRINTABLE) {                                \
        putchar('<');                                  \
        if (empty(vec)) {                              \
            puts(" >");                                \
        } else {                                       \
            printf(fmt, *(type *)front(vec));          \
            for (size_t i = 1; i < size(vec); i++) {   \
                printf(", ");                          \
                printf(fmt, *(type *)at_ptr(vec, i));  \
            }                                          \
            puts(">");                                 \
        }                                              \
    }                                                  \
} while (0)

#endif
