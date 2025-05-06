#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 10


typedef int elem;


typedef struct{
    int top;
    elem array[MAX_SIZE];
}Stack;

void ST_init(Stack *s);
int isFull(Stack s);
int isEmpty(Stack s);
int ST_push(Stack *s,elem x);
int ST_pop(Stack *s);


void ST_print(Stack s);









#endif // STACK_H