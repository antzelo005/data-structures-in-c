#include "heap.h"

#include <stdio.h>
#include <stdlib.h>



void swap(elem* a, elem* b){
    elem temp = *a;
    *a = *b;
    *b = temp;
}


void Heap_init(MinHeap* heap){

    heap->N = 0;
}

int Heap_insert(MinHeap* heap, elem x) {
    if (heap->N == MAX_SIZE)
        return 0; // Heap full

    // Insert at end
    int current = heap->N++;
    heap->data[current] = x;

    // Bubble up
    while (current > 0) {
        int parent = (current - 1) / 2;
        
        if (heap->data[parent] <= heap->data[current])
            break; // Heap property satisfied
        
        swap(&heap->data[parent], &heap->data[current]);
        current = parent;
    }
    
    return 1; // Success
}



int Heap_delete_min(MinHeap* heap, elem* min_value) {
    if (heap->N == 0)
        return 0; // Heap empty
    
    *min_value = heap->data[0]; // Store min value
    heap->data[0] = heap->data[--heap->N]; // Move last element to root

    // Bubble down
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;

        if (left < heap->N && heap->data[left] < heap->data[smallest])
            smallest = left;
        
        if (right < heap->N && heap->data[right] < heap->data[smallest])
            smallest = right;
        
        if (smallest == current)
            break; // Heap property satisfied
        
        swap(&heap->data[current], &heap->data[smallest]);
        current = smallest;
    }
    
    return 1; // Success
}

void Heap_print(MinHeap* heap) {
    printf("Heap (size %d): [", heap->N);
    for (int i = 0; i < heap->N; i++) {
        printf("%d", heap->data[i]);
        if (i < heap->N - 1) printf(", ");
    }
    printf("]\n");
}


















