#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists;
};

void DFS(struct Graph* graph, int vertex)
{
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while(temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if(graph->visited[connectedVertex] == 1)
        {
            printf("Cycle detected!\n");
            exit(1);
        }
        else
            DFS(graph, connectedVertex);
        temp = temp->next;
    }
}

struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    graph->visited = malloc(vertices * sizeof(int));

    for(int i = 0; i < vertices; ++i)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

int main()
{
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);

    DFS(graph, 0);

    return 0;
}
