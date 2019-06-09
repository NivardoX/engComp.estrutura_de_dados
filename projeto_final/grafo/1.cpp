#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
//--------------GLOBAIS---=-------------//
int V;
int MAX;
int aux_destinho_path;
//--------------------------------------//

//------------PROTOTIPOS----------------//
int minDistance(int dist[], bool setado[]); 
void printPath(int pai[], int j);
int printSolution(int dist[], int n,int pai[]); 
void dijkstra(int **graph, int fonte);
//--------------------------------------//

  

int count_pilha_recursao = 0;
void printPath(int pai[], int j) 
{ 
   
    if (pai[j] == - 1) {
        return; 
    }
    
    printPath(pai, pai[j]); 
    if (j == aux_destinho_path)
    {
     
    printf("%d.", j); 
     }else{

    printf("%d -> ", j); 
     }
} 

int minDistance(int dist[], bool setado[]){ 
    
    int min = INT_MAX, menor_index; 
  
    for (int v = 0; v < V; v++) 
        if (setado[v] == false && 
                   dist[v] <= min) 
            min = dist[v], menor_index = v; 
  
    return menor_index; 
} 
 
int printSolution(int dist[], int n,  
                      int pai[]) 
{ 
    printf("\n");
    int fonte = 0; 
    printf("Destino\t\t Distancia\t\tCaminho"); 
    for (int i = 1; i < V; i++) 
    { 
            if(!(dist[i] > V * MAX)){
            printf("\n%.2d \t\t %d\t\t%d -> ", 
                           i, dist[i], fonte); 
            aux_destinho_path = i;
            printPath(pai, i); 
            }else{
                printf("\n%.2d -> %.2d \t\t %s\t%s ", 
                          fonte, i, "INFINITO", "Não há caminho"); 
            }
    } 
} 
  
void dijkstra(int **graph, int fonte) 
{ 

    int dist[V];  

    bool setado[V]; 
  

    int pai[V]; 

    for (int i = 0; i < V; i++) 
    { 
        pai[0] = -1; 
        dist[i] = INT_MAX; 
        setado[i] = false; 
    } 

    dist[fonte] = 0; 
  

    for (int count = 0; count < V - 1; count++) 
    { 
        int u = minDistance(dist, setado); 

        setado[u] = true; 
  

        for (int v = 0; v < V; v++) 

            if (!setado[v] && graph[u][v] && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                pai[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    } 
  

    printSolution(dist, V, pai); 
} 
int main() 
{ 

    FILE *file;
    file=fopen("graph.txt", "r");
    
    fscanf(file,"%d,%d\n",&V,&MAX);
    

    int **graph;
    graph = (int**) malloc(sizeof(int* )* V);

    for (int i = 0; i < V; i++)
        graph[i] = (int*)malloc(sizeof(int)*V);
    

    printf("//--------------MATRIZ DE ADJACÊNCIA---------------------//\n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
        if (!fscanf(file, "%d, ", &graph[i][j])) 
            break;
         printf("%.2d ",graph[i][j]); 
        }

    printf("\n");

    }
    printf("//-------------------------------------------------------//\n");

    printf("\nO grafo têm %d vertices.\n", V);
    
    fclose(file);
    dijkstra(graph, 0); 
    printf("\n");

    for (int i = 0; i < V; i++)
        free(graph[i]); 

    free(graph);
    return 0; 
} 
