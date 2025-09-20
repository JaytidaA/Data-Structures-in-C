/*
 * linked_list.h
 * Implements a simple linked list in C
 * Author: https://github.com/JaytidaA/
 */

#ifndef DS_C_LINKED_LIST_H
#define DS_C_LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>

/* LinkedList_push_back: Push an element to the end of the list */
#define LinkedList_push_back(ll, type, elm) do {\
    type _temp = elm;                           \
    _LinkedList_push_back_ptr(ll, &_temp);      \
} while (0)

/* LinkedList_push_front: Push an element to the end of the list */
#define LinkedList_push_front(ll, type, elm) do {\
    type _temp = elm;                            \
    _LinkedList_push_front_ptr(ll, &_temp);      \
} while (0)

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    struct Node *head;
    struct Node *tail;
    size_t size;
    size_t elm_size;
} LinkedList;

/* prototypes */
LinkedList *new_list(size_t elm_size);
void delete_list(LinkedList *list);

void _LinkedList_push_back_ptr(LinkedList *list, void *item);
void _LinkedList_push_front_ptr(LinkedList *list, void *item);
void *LinkedList_front(LinkedList *list);
void *LinkedList_back(LinkedList *list);

size_t LinkedList_size(const LinkedList *list);

void *LinkedList_at_ptr(LinkedList *list, size_t index);

bool LinkedList_empty(const LinkedList *list);

#endif // DS_C_LINKED_LIST_H