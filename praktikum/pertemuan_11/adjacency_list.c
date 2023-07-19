#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        Node* temp = graph->adjList[v];
        printf("Adjacency list of vertex %d\n", v);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void destroyGraph(Graph* graph) {
    if (graph) {
        if (graph->adjList) {
            for (int i = 0; i < graph->numVertices; ++i) {
                Node* temp = graph->adjList[i];
                while (temp) {
                    Node* prev = temp;
                    temp = temp->next;
                    free(prev);
                }
            }
            free(graph->adjList);
        }
        free(graph);
    }
}

int main() {
    // Membuat graph dengan 5 vertex
    Graph* graph = createGraph(5);

    // Menambahkan edge
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Menampilkan graph
    printGraph(graph);

    // Membebaskan memory dari graph
    destroyGraph(graph);
    
    return 0;
}