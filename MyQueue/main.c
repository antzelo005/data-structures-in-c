#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    Q_init(&q);

    printf("Enqueue 8\n");
    Q_enqueue(&q, 8);
    printf("Enqueue 4\n");
    Q_enqueue(&q, 4);
    printf("Enqueue 3\n");
    Q_enqueue(&q, 3);

    printf("Current queue:\n");
    Q_print(q);

    printf("Dequeue one element...\n");
    Q_dequeue(&q);

    printf("Queue after dequeue:\n");
    Q_print(q);

    // Προσθήκη περισσότερων στοιχείων (π.χ. γέμισμα)
    for (int i = 10; i < 16; i++) {
        Q_enqueue(&q, i);
    }

    printf("Queue after adding more elements:\n");
    Q_print(q);

    // Άδειασμα ουράς
    while (!Q_isEmpty(q)) {
        Q_dequeue(&q);
        Q_print(q);
    }

    return 0;
}
