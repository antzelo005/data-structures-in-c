#include <stdio.h>
#include "queue.h" // Include the header file

int main() {
    Queue q;
    Q_init(&q);

    Q_enqueue(&q, 10);
    Q_enqueue(&q, 20);
    Q_enqueue(&q, 30);
    Q_enqueue(&q, 40);
    Q_enqueue(&q, 50);

    Q_display(q);

    elem x;
    Q_dequeue(&q, &x);
    printf("Dequeued: %d\n", x);

    Q_display(q);

    Q_enqueue(&q, 60);
    Q_display(q);

    return 0;
}