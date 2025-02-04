// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Number of vertices in the graph


// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[],int V)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[],int V)
{
	printf("\nVertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
    if(dist[i] == INT_MAX)
        printf("%d \t\t\t\t INF\n", i);
    else    
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int** graph, int src, int V)
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet, V);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist, V);
}

void freeG(int** graph, int size){
    for (int i = 0; i < size; i++)
    {
        int* currentIntPtr = graph[i];
        free(currentIntPtr);
    }
    free(graph);
}

// driver's code
int main()
{ 
    int size = 0;
    printf("Enter the size of the matrix: ");
    if(scanf("%d", &size)==0){
        printf("\nScanf error\n");
        return 0;
    }
    if(size <= 0){
        printf("\nSize must be greater than zero!\n");
        return 0;
    }
    int** graph = (int**)malloc(size * sizeof(int*));
    if(graph == NULL){
        printf("\nmalloc error\n");
        return 0;
    }
     for (int i = 0; i < size; i++) {
        graph[i] = malloc(size * sizeof(int));
        if (graph[i] == NULL) {
           printf("\nmalloc error\n");
           for(int j = 0; j < i; j++){
                free(graph[j]);
           }
           free(graph);
              return 0;
        }
    }
   for(int i = 0;i<size;i++){
    
    for(int j=0;j<size;j++){
        printf("\nEnter the value for the cell (%d,%d):", i, j);
        // 
        if(scanf("%d", &graph[i][j])==0){
            printf("\nScanf error\n");
            freeG(graph,size);
            return 0;
        }
        if(graph[i][j] < 0){
            printf("\nThe value must be at least zero!\n");
            freeG(graph,size);
            return 0;
        }
        if(i==j && graph[i][j]!=0){
             printf("\nAn edge from a vertex to itself isn't allowed!\n");
            freeG(graph,size);
            return 0;
        }
    }
   }
   int start = 0;
   printf("\nEnter the start vertex: ");
    if(scanf("%d", &start)==0){  
         printf("\nScanf error\n");
         freeG(graph,size);
         return 0;
    }
    if (start>=size || start<0)
    {
        printf("\nThe start vertex must be between 0 and %d\n", size-1);
        freeG(graph,size);
        return 0;
    }


   dijkstra(graph, start, size);
   freeG(graph,size);
	return 0;
}
