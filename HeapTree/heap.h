#define MAX_SIZE 100



typedef int elem;

typedef struct MinHeap{
    elem data[MAX_SIZE];
    int N; //our pointer to the last used position of the array 
}MinHeap;


void Heap_init(MinHeap* heap);
int Heap_insert(MinHeap* heap , elem x);
int Heap_delete_min(MinHeap* heap, elem* min_value) ;


// Utility functions
void Heap_print(MinHeap* heap);
void swap(elem* a, elem* b);





