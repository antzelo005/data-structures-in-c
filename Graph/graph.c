#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void GR_init(Graph* g, int N) {
    int i, j;
    g->N = N;

    g->array = (int**)malloc(sizeof(int*) * N);
    if (!g->array) {
        printf("Error allocating memory\n");
        exit(1);
    }

    for (i = 0; i < N; i++) {
        g->array[i] = (int*)malloc(sizeof(int) * N);
        if (!g->array[i]) {
            printf("Error allocating memory\n");
            exit(1);
        }
        for (j = 0; j < N; j++) {
            g->array[i][j] = 0;
        }
    }
}

void GR_init_from_file(Graph* g, char* filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%d", &g->N);

    g->array = (int**)malloc(sizeof(int*) * g->N);
    if (!g->array) {
        printf("Error allocating memory\n");
        exit(1);
    }

    for (int i = 0; i < g->N; i++) {
        g->array[i] = (int*)malloc(sizeof(int) * g->N);
        if (!g->array[i]) {
            printf("Error allocating memory\n");
            exit(1);
        }
        for (int j = 0; j < g->N; j++) {
            g->array[i][j] = 0;
        }
    }

    int i, j;
    while (fscanf(fp, "%d %d", &i, &j) == 2) {
        GR_add_edge(g, i, j);
    }

    fclose(fp);
}

void GR_print(Graph g) {
    int i, j;
    printf("    ");
    for (i = 0; i < g.N; i++)
        printf("%3d", i);
    printf("\n");

    for (i = 0; i < g.N; i++) {
        printf("%3d|", i);
        for (j = 0; j < g.N; j++)
            printf("%3d", g.array[i][j]);
        printf("\n");
    }
}

void GR_add_edge(Graph* g, int vertex1, int vertex2) {
    if (vertex1 < 0 || vertex1 >= g->N || vertex2 < 0 || vertex2 >= g->N) {
        printf("Error: Out of bounds!\n");
        exit(1);
    }
    if (g->array[vertex1][vertex2] == 1) {
        printf("Already in Graph\n");
        return;
    }

    g->array[vertex1][vertex2] = 1;
    g->array[vertex2][vertex1] = 1;
}

void GR_destroy(Graph g) {
    for (int i = 0; i < g.N; i++) {
        free(g.array[i]);
    }
    free(g.array);
}
