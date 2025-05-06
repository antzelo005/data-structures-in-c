#include <stdio.h>
#include "graph.h"



int main(){
    Graph g;
    GR_init_from_file(&g,"test.txt");
    GR_print(g);

    
    return 0;
}