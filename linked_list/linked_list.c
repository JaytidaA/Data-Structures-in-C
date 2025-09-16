/*
 * linked_list.c
 * Implements a simple linked list in C
 * Author: https://github.com/JaytidaA
 */

#include <stdlib.h>
#include <string.h>
#include "err_handle.h"
#include "linked_list/linked_list.h"

/******************************************************************************
 * new_list: Creates and initialises a new empty linked list with no nodes.   *
 *           Exits the program on failure to allocate enough memory.          *
 ******************************************************************************/
LinkedList *new_list(size_t e)
{
    LinkedList *temp = (LinkedList *) malloc(sizeof(LinkedList));
    if (!temp)
        err_null_malloc(__func__, sizeof(LinkedList));

    temp->size = 0;
    temp->elm_size = e;
    temp->head = NULL;
    temp->tail = NULL;

    return temp;
}

/******************************************************************************
 * delete_list: Delete a LinkedList and all of it's Nodes.                    *
 ******************************************************************************/
void delete_list(LinkedList *l)
{
    for (Node *temp = l->head->next; l->head != l->tail; temp = l->head->next) {
        free(l->head->data);
        free(l->head);
        l->head = temp;
    }
    free(l->head);
    free(l);
}

/******************************************************************************
 * _LinkedList_push_back_ptr: Adds an Item at the end of the LinkedList by    *
 *                            creating a new node and updating the next poin- *
 *                            ter of the tail node.                           *
 ******************************************************************************/
void _LinkedList_push_back_ptr(LinkedList *l, void *i)
{
    Node *node = (Node *) malloc(sizeof(Node));
    if (!node)
        err_null_malloc(__func__, sizeof(Node));

    node->data = (void *) malloc(l->elm_size);
    if (!node->data)
        err_null_malloc(__func__, l->elm_size);
    memcpy(node->data, i, l->elm_size);

    node->next = NULL;

    if (l->tail == NULL)
        l->tail = node;
    else
        l->tail->next = node;

    ++(l->size);
}

/******************************************************************************
 * _LinkedList_push_front_ptr: Adds an Item at the start of the LinkedList by *
 *                             creating a new node and updating the head poi- *
 *                             ter of the list accordingly.                   *
 ******************************************************************************/
void _LinkedList_push_front_ptr(LinkedList *l, void *i)
{
    Node *node = (Node *) malloc(sizeof(Node));
    if (!node)
        err_null_malloc(__func__, sizeof(Node));

    node->data = (void *) malloc(l->elm_size);
    if (!node->data)
        err_null_malloc(__func__, l->elm_size);
    memcpy(node->data, i, l->elm_size);

    node->next = l->head;
    l->head = node;

    ++(l->size);
}

/******************************************************************************
 * LinkedList_front: Returns a pointer to the first data element of the       *
 *                   LinkedList.                                              *
 ******************************************************************************/
void *LinkedList_front(LinkedList *l)
{
    return LinkedList_empty(l) ? NULL : l->head->data;
}

/******************************************************************************
 * LinkedList_front: Returns a pointer to the last data element of the        *
 *                   LinkedList.                                              *
 ******************************************************************************/
void *LinkedList_back(LinkedList *l)
{
    return LinkedList_empty(l) ? NULL : l->tail->data;
}

/******************************************************************************
 * LinkedList_size: Returns the number of nodes in the LinkedList.            *
 ******************************************************************************/
size_t LinkedList_size(const LinkedList *l)
{
    return l->size;
}

/******************************************************************************
 * LinkedList_at_ptr: Returns a pointer to the data element of the LinkedList *
 *                    present at index index.                                 *
 ******************************************************************************/
void *LinkedList_at_ptr(LinkedList *l, size_t i)
{
    if (i >= l->size)
        return NULL;
    Node *temp = l->head;
    while (i) {
        temp = temp->next;
        --i;
    }
    return temp->data;
}

/******************************************************************************
 * LinkedList_empty: Returns whether LinkedList is empty or not.              *
 ******************************************************************************/
bool LinkedList_empty(const LinkedList *l)
{
    return (bool) (l->size);
}
