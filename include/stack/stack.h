/*
 * stack.h
 * Implements a simple stack in C
 * Author: https://github.com/crisiumnih
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

/* Special value to indicate that the stack is empty */
#define STACK_EMPTY NULL

typedef struct node {
    void *value;
    struct node *next;
} node;

typedef struct {
    node *head;
    size_t elm_size;
} Stack;

/* Stack management */
Stack *create_stack(size_t elm_size);
void free_stack(Stack *s);

/* Main */
void push(Stack *s, void *value);
void *pop(Stack *s);
void *top(const Stack *s);

/* Utility functions */
bool empty(const Stack *s);
size_t stack_size(const Stack *s);

#endif