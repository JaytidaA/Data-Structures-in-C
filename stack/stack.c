/*
 * stack.c
 * Implements a simple stack in C
 * Author: https://github.com/crisiumnih
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "err_handle.h"
#include "stack/stack.h"

/* --- Stack management --- */

/******************************************************************************
 * create_stack: Creates a new empty stack.                                   *
 ******************************************************************************/
Stack *create_stack(size_t elm_size){
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL) err_null_malloc("create_stack", sizeof(Stack));
    s->head = NULL;
    s->elm_size = elm_size;
    return s;
}

/******************************************************************************
 * free_stack: Frees all the nodes in the stack and sets the stack pointer    *
 *             to NULL.                                                       *
 ******************************************************************************/
void free_stack(Stack *s){
    node *curr = s->head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp->value);
        free(temp);
    }
    s->head = NULL;
}

/******************************************************************************
 * push: Adds a new element to the top of the stack.                          *
 ******************************************************************************/
void push(Stack *s, void *v){
    node *temp = malloc(sizeof(node));
    if (temp == NULL) err_null_malloc("push", sizeof(node));

    temp->value = malloc(s->elm_size);
    memcpy(temp->value, v, s->elm_size);

    temp->next = s->head;
    s->head = temp;
}

/******************************************************************************
 * pop: Removes and returns the top element of the stack. Returns             *
 *      STACK_EMPTY (NULL) if the stack is empty.                             *
 ******************************************************************************/
void *pop(Stack *s){
    if (s->head == NULL) return STACK_EMPTY;

    void *result = s->head->value;
    node *temp = s->head;
    s->head = s->head->next;
    free(temp);
    return result;
}

/******************************************************************************
 * top: Returns the top element of the stack without removing it. Returns     *
 *      STACK_EMPTY (NULL) if the stack is empty.                             *
 ******************************************************************************/
void *top(const Stack *s) {
    if (s->head == NULL) return STACK_EMPTY;
    return s->head->value;
}

/******************************************************************************
 * empty: Returns true if the stack is empty, false otherwise.                *
 ******************************************************************************/
bool empty(const Stack *s){
    return s->head == NULL;
}

/******************************************************************************
 * stack_size: Returns the number of elements in the stack.                   *
 ******************************************************************************/
size_t stack_size(const Stack *s){
    size_t size = 0;
    node *curr = s->head;
    while (curr != NULL) {
        size++;
        curr = curr->next;
    }
    return size;
}