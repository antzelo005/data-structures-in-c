#include "queue.h"
#include <stdio.h>





int main(){
    printf("hello world\n");
    Queue q;
    Q_init(&q);
    Q_enqueue(&q,8);
    Q_enqueue(&q,4);
    Q_enqueue(&q,3);
    Q_print(q);
    Q_dequeue(&q);
    Q_print(q);



    return 0;
}




