#include <stdio.h>
#include <stdlib.h>

struct Graph
{
    int numVertices;
    int **adjMatrix;
};

// Fungsi untuk membuat graph dengan vertex awal
struct Graph *createGraph()
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = 0;
    graph->adjMatrix = NULL;
    return graph;
}

// Fungsi untuk menambahkan vertex baru ke dalam graph
void addVertex(struct Graph *graph)
{
    int newVertices = graph->numVertices + 1;

    // Alokasi memori untuk adjacency matrix baru
    graph->adjMatrix = (int **)realloc(graph->adjMatrix, newVertices * sizeof(int *));
    graph->adjMatrix[newVertices - 1] = (int *)malloc(newVertices * sizeof(int));

    int i;
    for (i = 0; i < newVertices; i++)
    {
        graph->adjMatrix[i] = (int *)realloc(graph->adjMatrix[i], newVertices * sizeof(int));
        graph->adjMatrix[i][newVertices - 1] = 0;
        graph->adjMatrix[newVertices - 1][i] = 0;
    }

    graph->numVertices++;
}

// Fungsi untuk menambahkan sisi antara dua simpul dalam graph
void addEdge(struct Graph *graph, int src, int dest)
{
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices)
    {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
    }
    else
    {
        printf("Invalid vertex!\n");
    }
}

// Fungsi untuk mencetak adjacency matrix
void printGraph(struct Graph *graph)
{
    int i, j;
    for (i = 0; i < graph->numVertices; i++)
    {
        for (j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Fungsi utama
int main()
{
    struct Graph *graph = createGraph();
    printGraph(graph);
    int pilihan;
    do
    {
        printGraph(graph);
        printf("Menu\n1.Buat Vertex Baru\n2.Buat Edge\nMasukkan pilihan : ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            addVertex(graph);
        }
        else if (pilihan == 2)
        {
            int src, dst;
            scanf("%d %d", &src, &dst);
            addEdge(graph, src, dst);
        }
        system("cls");

    } while (pilihan != 0);
}