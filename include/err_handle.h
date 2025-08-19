/*
 * err_handle.h
 * Basic error handling functions and macros
 * Author: https://github.com/JaytidaA/
 */

#ifndef ERR_HANDLE_H
#define ERR_HANDLE_H

#include "utils.h"
#include <stdlib.h>

#if IS_PRINTABLE
#include <stdio.h>
#endif

static inline void err_null_malloc(const char *func, size_t size) {
#if IS_PRINTABLE
	fprintf(stderr, "[ERROR] (%s): Could not allocate %zu elements!\n", func, size);
#endif
	exit(EXIT_FAILURE);
}

#endif
