#ifndef LLIST
#define LLIST
#include <stdio.h>
#include <stdlib.h>


typedef int elem;

typedef struct Node{
    elem data;
    struct Node* next;
}Node;

typedef Node* NodePtr;


void LL_init(NodePtr *head);
int LL_empty(NodePtr head);
int LL_insert_start(NodePtr *head,elem x);
int LL_insert_after(NodePtr prev,elem x);
int LL_delete_start(NodePtr *head,elem* x);
int LL_delete_after(NodePtr prev,elem* x);
int LL_destroy(NodePtr *head);
void LL_print(NodePtr head);







#endif