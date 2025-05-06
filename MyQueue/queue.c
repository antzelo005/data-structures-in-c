#include "queue.h"
#include <stdio.h>

/*
void Q_init(Queue* q);
int Q_full(Queue q);
int Q_empty(Queue q);
int Q_enqueue(Queue* q,elem x);
int Q_dequeue(Queue* q);

void ST_print(Queue q);
*/


void Q_init(Queue* q){
    q->finish = -1;
}


int Q_full(Queue q){
    return q.finish == MAX_SIZE;
}

int Q_empty(Queue q){
    return q.finish == -1;
}

int Q_enqueue(Queue* q,elem x){
    if(Q_full(*q)){
        printf("Error 404 full QUEUE");
        return 0;
    }
    else{
        q->array[++(q->finish)]=x;
        return 1;
    }
}

int Q_dequeue(Queue* q){
    if(Q_empty(*q)){

        printf("ERROR 404 empty QUEUE");
        return 0;
    }
    else{

        int i;

        for(i=0;i<q->finish;i++){
            q->array[i] = q->array[i+1]; 
        }
        q->finish--;
        return 1;
    }

}


void Q_print(Queue q){

    int i;
    for(i=0;i<q.finish;i++){
        printf("| %d ",q.array[i]);
    }
    printf("|\n");

}