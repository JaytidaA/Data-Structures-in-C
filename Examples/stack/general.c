/*
 * general.c
 * A general example for the stack.
 * Author: https://github.com/crisiumnih
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack/stack.h"

int main() {
    Stack *s = create_stack(sizeof(int));

    printf("Address of stack pointer 's': %p\n", (void *)s);
    printf("Stack created.\n");
    printf("Stack is empty: %s\n", empty(s) ? "true" : "false");

    printf("\nPushing integers 10, 20, 30...\n");

    int val1 = 10;
    push(s, &val1);

    int val2 = 20;
    push(s, &val2);

    int val3 = 30;
    push(s, &val3);

    printf("Stack size: %zu\n", stack_size(s));
    printf("Top element is: %d\n", *(int*)top(s));

    printf("\nPopping one element...\n");
    int *popped = pop(s);
    if (popped != NULL) {
        printf("Popped: %d\n", *popped);
    }

    printf("Stack size: %zu\n", stack_size(s));
    printf("Top element is now: %d\n", *(int*)top(s));

    printf("\nPopping all remaining elements...\n");
    while (!empty(s)) {
        popped = pop(s);
        if (popped != NULL) {
            printf("Popped: %d\n", *popped);
        }
    }

    printf("\nStack is empty: %s\n", empty(s) ? "true" : "false");

    free_stack(s);
    printf("Stack freed.\n");

    return 0;
}