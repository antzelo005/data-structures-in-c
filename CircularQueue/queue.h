#ifndef QUEUE_H // Include guard to prevent multiple inclusions
#define QUEUE_H

#define MAX_SIZE 5 // Define MAX_SIZE only once

typedef int elem; // Define the type of elements in the queue

typedef struct {
    elem array[MAX_SIZE];
    int start;
    int finish;
} Queue;

// Function prototypes
void Q_init(Queue* q);
int Q_empty(Queue q);
int Q_full(Queue q);
int Q_enqueue(Queue* q, elem x);
int Q_dequeue(Queue* q, elem* x);
void Q_display(Queue q);

#endif // QUEUE_H