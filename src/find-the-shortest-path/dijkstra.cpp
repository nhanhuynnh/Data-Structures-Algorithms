
#include <iostream>
using namespace std; 
#define V 5 
int minimum(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
    return min_index; 
} 
void print(int dist[]) 
{ 
    cout<<"Dinh \t\t Khoang cach"<<endl;
    for (int i = 0; i < V; i++) 
        cout<<i<<"\t\t"<<dist[i]<<endl;
} 
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; 
    bool sptSet[V]; 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
    dist[src] = 0; 
  
    for (int count = 0; count < V - 1; count++) {  
        int u = minimum(dist, sptSet); 
        sptSet[u] = true; 
   
        for (int v = 0; v < V; v++) 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
    print(dist); 
} 
int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 3 }, 
                        { 4, 0, 5, 0, 0 }, 
                        { 0, 5, 0, 6, 0 }, 
                        { 0, 0, 6, 0, 7 }, 
                        { 3, 0, 0, 7, 0 }
                      }; 

    dijkstra(graph, 0); 
    system("pause");
    return 0; 
} 