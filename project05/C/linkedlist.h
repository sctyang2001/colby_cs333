/**
* cstk.h: The program declares the basic functions of the Linked List data structure.
* (This file is linked with "linkedlist.c".)
*
* Scottie YANG Miaoyi
* Mar 30, 2022
*/

#ifndef linkedlist
#define linkedlist

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void * val;
    struct Node * prev;
    struct Node * next;
} Node;

typedef struct LinkedList { 
    int size; 
    Node *head;
    Node *tail; 
} LinkedList;

// Required by task.
LinkedList *ll_create();
void ll_push(LinkedList *l, void *data); 
void *ll_pop(LinkedList *l); 
void ll_append(LinkedList *l, void *data);
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)); 
int ll_size(LinkedList *l);
void ll_clear(LinkedList *l, void (*freefunc)(void *));
void ll_map(LinkedList *l, void (*mapfunc)(void *)); 

#endif /* linkedlist */

