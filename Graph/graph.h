




typedef struct{
    int** array;
    int N;
}Graph;



void GR_init(Graph* g , int N);
void GR_init_from_file(Graph* g, char* filename);
void GR_print(Graph g);
void GR_add_edge(Graph *g,int vertex1,int vertex2);
void GR_destroy(Graph g);