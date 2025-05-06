#include "stack.h"  // Include the stack header file
#include <stdio.h>


/*
void ST_init(Stack *s);
int isFull(Stack s);
int isEmpty(Stack s);
int ST_push(Stack *s,elem x);
int ST_pop(Stack *s);
int ST_print(Stack s);
*/




void ST_init(Stack *s){
    s->top = -1;
}

int isFull(Stack s){
    return s.top == MAX_SIZE;
}

int isEmpty(Stack s){
    return s.top==-1;
}

int ST_push(Stack *s,elem x){
    if(isFull(*s)){
        printf("Error 404 isFull");
        return 0;
    }
    else{
        s->array[++(s->top)]=x;
        return 1;
    }
}

int ST_pop(Stack *s){
    if(isEmpty(*s)){
        printf("Error 404 isEmpty");
        return 0;
    }
    else{
        s->array[--(s->top)];
    }
}


void ST_print(Stack s){

    int i=-1;
    
    while(i< s.top ){
        printf("| %d ",s.array[i+1]);
        i++;
    }
    printf("|\n");
}