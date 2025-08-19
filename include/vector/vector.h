/*
 * vector.h
 * Implements a simple vector in C
 * Author: https://github.com/JaytidaA/
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_VEC_CAP 1
#define LINEAR_ALLOC

#if defined(EXP_ALLOC)
#undef LINEAR_ALLOC
#endif

#if defined(LINEAR_ALLOC)
#define ALLOC_CONST 5
#elif defined(EXP_ALLOC)
#define ALLOC_CONST 1.5
#endif

/* push_back: Push an element to the end of the vector */
#define push_back(vec, type, elm) do {\
    type _temp = elm;                 \
    _push_back_ptr(vec, &_temp);      \
} while (0)

typedef struct {
    void *arr;
    size_t elm_size;
    size_t size;
    size_t capacity;
} Vector;

/* prototypes */
Vector *new_vector(size_t elm_size);
Vector *new_vector_cap(size_t elm_size, size_t n);
Vector *new_vector_fill(size_t elm_size, size_t n, void *i);
Vector *reset_vector(Vector *);
void delete_vector(Vector *);

void _push_back_ptr(Vector *v, void *i);
void pop_back(Vector *v);
void *front(const Vector *v);
void *back(const Vector *v);

size_t size(const Vector *v);
size_t capacity(const Vector *v);

void *at_ptr(const Vector *v, size_t i);

bool empty(const Vector *v);
void clear(Vector *v);

#endif
