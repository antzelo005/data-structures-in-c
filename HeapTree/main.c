#include "heap.h"
#include <stdio.h>

void print_heap_operation(const char* operation, MinHeap* heap) {
    printf("%-20s", operation);
    Heap_print(heap);
}

int main() {
    MinHeap heap;
    Heap_init(&heap);
    
    printf("=== MinHeap Demonstration ===\n\n");
    
    // Insertion sequence
    printf("Inserting elements:\n");
    int elements[] = {15, 3, 8, 1, 12, 7, 4};
    for (int i = 0; i < sizeof(elements)/sizeof(elements[0]); i++) {
        char msg[32];
        snprintf(msg, sizeof(msg), "Insert %d:", elements[i]);
        Heap_insert(&heap, elements[i]);
        print_heap_operation(msg, &heap);
    }
    
    // Deletion sequence
    printf("\nExtracting minimum elements:\n");
    elem min_val;
    while (heap.N > 0) {
        Heap_delete_min(&heap, &min_val);
        char msg[32];
        snprintf(msg, sizeof(msg), "Extracted %d:", min_val);
        print_heap_operation(msg, &heap);
    }
    
    printf("\nFinal heap size: %d\n", heap.N);
    return 0;
}