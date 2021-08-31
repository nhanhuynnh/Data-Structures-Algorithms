
#include <iostream>
using namespace std; 
#define V 5  // Số đỉnh trong đồ thị 

int minKey(int key[], bool mstSet[])  
{  
    int min = INT_MAX, min_index;  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
void print(int parent[], int graph[V][V])  
{  
    cout<<"Canh \tChi So\n";  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}       
void prim(int graph[V][V])  
{  
    int parent[V];  
    int key[V];  
    bool mstSet[V];  
    // Khởi tạo tất cả các khóa dưới dạng vô hạn
    for (int i = 0; i < V; i++)  
    {
        key[i] = INT_MAX, mstSet[i] = false;  
    }
    key[0] = 0;  
    parent[0] = -1; // Nút đầu tiên luôn là gốc của MST
  
    for (int count = 0; count < V - 1; count++) 
    {  
        int u = minKey(key, mstSet);  
        mstSet[u] = true;  
        for (int v = 0; v < V; v++)  
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
    // in MST đã xây dựng 
    print(parent, graph);  
}  
int main()  
{  

    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    
    prim(graph);  
    system("pause");
    return 0;  
}  
  