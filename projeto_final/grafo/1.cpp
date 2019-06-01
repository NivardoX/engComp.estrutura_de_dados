
// C program for Dijkstra's single  
// source shortest path algorithm. 
// The program is for adjacency matrix 
// representation of the graph. 
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
// Number of vertices  
// in the graph 
int V;
int MAX;
int aux_destinho_path;
  
// A utility function to find the  
// vertex with minimum distance 
// value, from the set of vertices 
// not yet included in shortest 
// path tree 
int minDistance(int dist[],  
                bool sptSet[]) 
{ 
      
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
// Function to print shortest 
// path from source to j 
// using parent array 
int count_pilha_recursao = 0;
void printPath(int parent[], int j) 
{ 
    // Base Case : If j is source 
    if (parent[j] == - 1) {
        return; 
    }
    
    printPath(parent, parent[j]); 
    if (j == aux_destinho_path)
    {
     
    printf("%d.", j); 
     }else{

    printf("%d -> ", j); 
     }
} 
  
// A utility function to print  
// the constructed distance 
// array 
int printSolution(int dist[], int n,  
                      int parent[]) 
{ 
    int src = 0; 
    printf("Vertice\t\t Distancia\t\tCaminho"); 
    for (int i = 1; i < V; i++) 
    { 
        if(!(dist[i] > V * MAX)){
        printf("\n%.2d -> %.2d \t\t %d\t\t%d -> ", 
                      src, i, dist[i], src); 
        aux_destinho_path = i;
        printPath(parent, i); 
        }else{
            printf("\n%.2d -> %.2d \t\t %s\t%s ", 
                      src, i, "INFINITO", "Não há caminho"); 
        }
    } 
} 
  
// Funtion that implements Dijkstra's 
// single source shortest path 
// algorithm for a graph represented 
// using adjacency matrix representation 
void dijkstra(int **graph, int src) 
{ 
      
    // The output array. dist[i] 
    // will hold the shortest 
    // distance from src to i 
    int dist[V];  
  
    // sptSet[i] will true if vertex 
    // i is included / in shortest 
    // path tree or shortest distance  
    // from src to i is finalized 
    bool sptSet[V]; 
  
    // Parent array to store 
    // shortest path tree 
    int parent[V]; 
  
    // Initialize all distances as  
    // INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
    { 
        parent[0] = -1; 
        dist[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
  
    // Distance of source vertex  
    // from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path 
    // for all vertices 
    for (int count = 0; count < V - 1; count++) 
    { 
        // Pick the minimum distance 
        // vertex from the set of 
        // vertices not yet processed.  
        // u is always equal to src 
        // in first iteration. 
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex  
        // as processed 
        sptSet[u] = true; 
  
        // Update dist value of the  
        // adjacent vertices of the 
        // picked vertex. 
        for (int v = 0; v < V; v++) 
  
            // Update dist[v] only if is 
            // not in sptSet, there is 
            // an edge from u to v, and  
            // total weight of path from 
            // src to v through u is smaller 
            // than current value of 
            // dist[v] 
            if (!sptSet[v] && graph[u][v] && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    } 
  
    // print the constructed 
    // distance array 
    printSolution(dist, V, parent); 
} 
  
// Driver Code 
int main() 
{ 
    //  Let us create the example 
    // graph discussed above 
    FILE *file;
    file=fopen("graph.txt", "r");
    
    fscanf(file,"%d,%d\n",&V,&MAX);
    
    int **graph;
    graph = (int**) malloc(sizeof(int* )* V);

    for (int i = 0; i < V; i++)
        graph[i] = (int*)malloc(sizeof(int)*V);
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
        if (!fscanf(file, "%d, ", &graph[i][j])) 
            break;
        // mat[i][j] -= '0'; 
         printf("%.2d ",graph[i][j]); //Use lf format specifier, \n is for new line
        }

    printf("\n");

    }

    fclose(file);
    dijkstra(graph, 0); 
    printf("\n");

    for (int i = 0; i < V; i++)
        free(graph[i]); 

    free(graph);
    return 0; 
} 
