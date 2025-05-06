#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
void LL_init(NodePtr *head);
int LL_empty(NodePtr head);
int LL_insert_start(NodePtr *head,elem x);
int LL_insert_after(NodePtr prev,elem x);
int LL_delete_start(NodePtr *head,elem* x);
int LL_delete_after(NodePtr prev,elem* x);
int LL_destroy(NodePtr *head);
void LL_print(NodePtr head);
*/


void LL_init(NodePtr *head){
    *head = NULL;
}

int LL_empty(NodePtr head){
    return head==NULL;
}

int LL_insert_start(NodePtr *head,elem x){

    NodePtr newNode=(NodePtr)malloc(sizeof(Node));
    if(!newNode){
        printf("fail memory allocation");
        return 0;
    }
    newNode->data = x;
    newNode->next =*head;
    *head = newNode;
    return 1;
}
int LL_insert_after(NodePtr prev,elem x){

    if (prev == NULL) {
        printf("Ο προηγούμενος κόμβος δεν μπορεί να είναι NULL.\n");
        return 0;  // ή -1 αν ακολουθείς την πρακτική επιστροφής μη μηδενικών τιμών για σφάλματα
    }

    NodePtr newNode=(NodePtr)malloc(sizeof(Node));
    if(!newNode){
        printf("fail memory allocation");
        return 0;
    }
    newNode->data = x;
    newNode->next = prev->next;

    prev->next = newNode;
    return 1;
}

int LL_delete_start(NodePtr *head,elem *x){

    if(LL_empty(*head)){
        printf("H lista einai adeia");
        return 0;
    }

    NodePtr cur= *head;
    *x = cur->data;

    *head = (*head)->next;

    free(cur);
    return 1;

}


int LL_delete_after(NodePtr prev,elem* x){

    if(prev==NULL || prev->next == NULL){
        printf("Sfalma: o prohgoymenos kombos h o epomenos einai NULL .\n");
        return 0; 
    }

    
    NodePtr cur = prev->next;
    *x = cur->data;
    prev->next = cur->next;

    free(cur);
    return 1;

}


int LL_destroy(NodePtr *head){


    if(LL_empty(*head) ){
        printf("H lista einai idh adeia! ");
        return 0;
    }

    NodePtr temp = *head;
    while((*head)->next !=NULL){
        
        free(temp);
        (*head) =(*head)->next;
        temp = (*head)->next;
    }

    free(*head);

    return 1;

}

void LL_print(NodePtr head){
    
    NodePtr temp = head;

    while( temp!= NULL){
        
        printf("|%d",temp->data);

        temp =temp->next;
    }
    printf("|\n");
}