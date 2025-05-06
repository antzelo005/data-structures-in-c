#include <stdio.h>
#include "queue.h" // Include the header file

// Initialize the queue
void Q_init(Queue* q) {
    q->finish = -1;
    q->start = -1;
}

// Check if the queue is empty
int Q_empty(Queue q) {
    return q.start == -1;
}

// Check if the queue is full
int Q_full(Queue q) {
    return q.start == (q.finish + 1) % MAX_SIZE;
}

// Add an element to the queue
int Q_enqueue(Queue* q, elem x) {
    if (Q_full(*q)) {
        printf("Error 404: Full queue!\n");
        return 0;
    } else {
        if (Q_empty(*q)) {
            q->start = 0; // Initialize start if the queue is empty
        }
        q->finish = (q->finish + 1) % MAX_SIZE; // Circular behavior
        q->array[q->finish] = x;
        return 1;
    }
}

// Remove an element from the queue
int Q_dequeue(Queue* q, elem* x) {
    if (Q_empty(*q)) {
        printf("Error 404: Empty queue!\n");
        return 0;
    } else {
        *x = q->array[q->start];
        if (q->start == q->finish) {
            // Reset the queue if it becomes empty after dequeue
            q->start = -1;
            q->finish = -1;
        } else {
            q->start = (q->start + 1) % MAX_SIZE; // Circular behavior
        }
        return 1;
    }
}

// Display the queue
void Q_display(Queue q) {
    if (Q_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = q.start;
    while (1) {
        printf("%d ", q.array[i]);
        if (i == q.finish) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}