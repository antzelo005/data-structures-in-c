#ifndef QUEUE_H
#define QUEUE_H
#define MAX_SIZE 10



typedef int elem;


typedef struct{
    elem array[MAX_SIZE];
    int finish;
}Queue;


void Q_init(Queue* q);
int Q_full(Queue q);
int Q_empty(Queue q);
int Q_enqueue(Queue* q,elem x);
int Q_dequeue(Queue* q);

void Q_print(Queue q);

#endif // QUEUE_H
