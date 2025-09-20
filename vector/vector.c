/*
 * vector.c
 * Implements a simple vector in C
 * Author: https://github.com/JaytidaA
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "err_handle.h"
#include "vector/vector.h"

/* internal helpers */
void vmem_reallocation(Vector *v);
size_t vnew_cap(size_t cap);

/******************************************************************************
 * new_vector: Creates and initialses a new empty vector with space for       *
 *             INITIAL_VEC_CAP Item(s). Exits the program on failure to       *
 *             allocate enough memory.                                        *
 ******************************************************************************/
Vector *new_vector(size_t e)
{
	Vector *temp = (Vector *) malloc(sizeof(Vector));
	if (!temp)
		err_null_malloc(__func__, sizeof(Vector));

	temp->size = 0;
	temp->capacity = INITIAL_VEC_CAP;
	temp->elm_size = e;
	temp->arr = malloc(temp->capacity * e);
	if (!(temp->arr))
		err_null_malloc(__func__, INITIAL_VEC_CAP);

	return temp;
}

/******************************************************************************
 * new_vector_cap: Creates and initialises a new empty vector with space for  *
 *                 'n' Items. Exits the program on failure to allocate enough *
 *                 memory.                                                    *
 ******************************************************************************/
Vector *new_vector_cap(size_t e, size_t n)
{
	Vector *temp = (Vector *) malloc(sizeof(Vector));
	if (!temp)
		err_null_malloc(__func__, sizeof(Vector));

	temp->size = 0;
	temp->capacity = (!n) ? INITIAL_VEC_CAP : n;
	temp->elm_size = e;
	temp->arr = malloc(temp->capacity * e);
	if (!(temp->arr))
		err_null_malloc(__func__, n * e);

	return temp;
}

/******************************************************************************
 * new_vector_fill: Creates and initialises a vector with space for 'n' Items *
 *                  and initialises them with value 'i'. Exits the progtam on *
 *                  failure to allocate enough memory.                        *
 ******************************************************************************/
Vector *new_vector_fill(size_t e, size_t n, void *i)
{
	if (!n)
		return NULL;

	Vector *temp = (Vector *) malloc(sizeof(Vector));
	if (!temp)
		err_null_malloc(__func__, sizeof(Vector));

	temp->size = n;
	temp->capacity = n;
	temp->elm_size = e;
	temp->arr = malloc(n * e);
	if (!(temp->arr))
		err_null_malloc(__func__, n * e);
	
	for (int j = 0; j < n; j++)
		memcpy(temp->arr + (j * e), i, e);

	return temp;
}

/******************************************************************************
 * reset_vector: Resets the vector so that it is indistinguishable from one   *
 *               which is newly declared. Frees the array and sets the size,  *
 *               capacity and elm_size to zero.                               *
 ******************************************************************************/
Vector *reset_vector(Vector *v)
{
	free(v->arr);
	v->size = v->capacity = v->elm_size = 0;
	return v;
}

/******************************************************************************
 * delete_vector: Calls reset_vector and frees the pointer returned by it.    *
 ******************************************************************************/
void delete_vector(Vector *v)
{
	free(reset_vector(v));
}

/******************************************************************************
 * _push_back_ptr: Adds an Item at the location pointed to by size and        *
 *                 increments it by one. Reallocates memory if size is equal  *
 *                 to the capacity.                                           *
 ******************************************************************************/
void _push_back_ptr(Vector *v, void *i)
{
	if (v->size == v->capacity)
		vmem_reallocation(v);
	memcpy(((uint8_t *) v->arr) + (v->elm_size * (v->size)++), i, v->elm_size);
}

/******************************************************************************
 * pop_back: Removes one from Item the back if vector is not empty.           *
 ******************************************************************************/
void pop_back(Vector *v)
{
	if (!empty(v))
		v->size -= 1;
}

/******************************************************************************
 * front: Returns a pointer to the first Item in the vector, NULL if empty.   *
 ******************************************************************************/
void *front(const Vector *v)
{
	return empty(v) ? NULL : v->arr;
}

/******************************************************************************
 * back: Returns a pointer to the last Item of the vector, NULL if empty.     *
 ******************************************************************************/
void *back(const Vector *v)
{
	return empty(v) ? NULL : (((uint8_t *) v->arr) + ((v->size - 1) * v->elm_size));
}

/******************************************************************************
 * size: Returns the current number of Items in the vector.                   *
 ******************************************************************************/
size_t size(const Vector *v)
{
	return v->size;
}

/******************************************************************************
 * capacity: Returns the maximum number of Items the vector can hold before   *
 *           needed to perform a reallocation.                                *
 ******************************************************************************/
size_t capacity(const Vector *v)
{
	return v->capacity;
}

/******************************************************************************
 * at_ptr: Retunrs a pointer to the ith Item in the vector, NULL if invalid.  *
 ******************************************************************************/
void *at_ptr(const Vector *v, size_t i)
{
	return (i >= v->size) ? NULL : (((uint8_t *) v->arr) + (i * v->elm_size));
}

/******************************************************************************
 * empty: Returns the comparision of the size of the vector with 0.           *
 ******************************************************************************/
bool empty(const Vector *v)
{
	return (v->size == 0);
}

/******************************************************************************
 * clear: Sets size to zero so that new elments are filled at the start.      *
 ******************************************************************************/
void clear(Vector *v)
{
	v->size = 0;
}

/******************************************************************************
 * vmem_reallocation: Allocates more memory on the heap based on the current  *
 *                    capacity of the vector and copies the Items to the new- *
 *                    ly allocated memory. Makes the array point to this new- *
 *                    ly allocated memory and frees the old memory.           *
 ******************************************************************************/
void vmem_reallocation(Vector *v)
{
	size_t new_cap = vnew_cap(v->capacity);
	void *temp = malloc(new_cap * v->elm_size);
	if (!temp)
		err_null_malloc(__func__, new_cap);

	memcpy(temp, v->arr, v->size * v->elm_size);
	free(v->arr);
	v->arr = temp;
	v->capacity = new_cap;
}

/******************************************************************************
 * vnew_cap: Function to determine the increased capacity of vector after re- *
 *           allocation. Makes use of the macros LINEAR_ALLOC and EXP_ALLOC   *
 *           to determine the new capacity.                                   *
 ******************************************************************************/
size_t vnew_cap(size_t cap)
{
#if defined(LINEAR_ALLOC)
	return cap + ALLOC_CONST;
#elif defined(EXP_ALLOC)
	return cap * ALLOC_CONST;
#endif
}
