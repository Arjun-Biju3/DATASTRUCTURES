#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head; 
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
         printf("\n%d  ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
void DFSUtil(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct AdjListNode* pCrawl = graph->array[v].head;
    while (pCrawl) {
        int u = pCrawl->dest;
        if (!visited[u])
            DFSUtil(graph, u, visited);
        pCrawl = pCrawl->next;
    }
}

void fillOrder(struct Graph* graph, int v, int visited[], int stack[], int* top) {
    visited[v] = 1;
    struct AdjListNode* pCrawl = graph->array[v].head;
    while (pCrawl) {
        int u = pCrawl->dest;
        if (!visited[u])
            fillOrder(graph, u, visited, stack, top);
        pCrawl = pCrawl->next;
    }
    stack[(*top)++] = v;
}

struct Graph* transpose(struct Graph* graph) {
    struct Graph* g = createGraph(graph->V);

    for (int v = 0; v < graph->V; v++) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl) {
            addEdge(g, pCrawl->dest, v);
            pCrawl = pCrawl->next;
        }
    }

    return g;
}

void printSCCs(struct Graph* graph) {
    int stack[graph->V];
    int top = 0;
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    for (int i = 0; i < graph->V; i++)
        if (!visited[i])
            fillOrder(graph, i, visited, stack, &top);

    struct Graph* gr = transpose(graph);

    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    printf("The strongly connected components are:\n");
    while (top > 0) {
        int v = stack[--top];

        if (!visited[v]) {
            DFSUtil(gr, v, visited);
            printf("\n");
        }
    }
}
int main() {
    int v,v1,v2,e;
    printf("Enter the number of vertex :");
    scanf("%d",&v);
    struct Graph* graph = createGraph(v);
    printf("Enter the number of edges :");
    scanf("%d",&e);
    printf("Enter the edges (v1,v2) :");
    for(int i =0;i<e;i++){
     scanf("%d",&v1);
     scanf("%d",&v2);
     addEdge(graph, v1,v2);
    }
    printf("\nAdjacency list\n");
    printGraph(graph);
    printSCCs(graph);
    return 0;
}
