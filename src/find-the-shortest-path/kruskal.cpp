#include<iostream>
using namespace std;
 
class Edge {
public:
    int src, dest, weight;
};
class Graph {
public:
    int V, E;
    Edge* e;
};
Graph* createGraph(int V, int E)
{
    Graph* g = new Graph;
    g->V = V;
    g->E = E;
    g->e = new Edge[E];
    return g;
}
class subset {
public:
    int parent;
    int rank;
};
int find(subset s[], int i)
{
    if (s[i].parent != i)
        s[i].parent = find(s, s[i].parent);
    return s[i].parent;
}
void Union(subset s[], int x, int y)
{
    int xroot = find(s, x);
    int yroot = find(s, y);
 
    if (s[xroot].rank < s[yroot].rank)
        s[xroot].parent = yroot;
    else if (s[xroot].rank > s[yroot].rank)
        s[yroot].parent = xroot;
    else {
        s[yroot].parent = xroot;
        s[xroot].rank++;
    }
}
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
void Kruskal(Graph* graph)
{
    int V = graph->V;
    Edge result[V]; 
    int e = 0; 
    int i = 0; 
    qsort(graph->e, graph->E, sizeof(graph->e[0]), myComp);
 
    subset* s = new subset[(V * sizeof(subset))];
    for (int v = 0; v < V; ++v) 
    {
        s[v].parent = v;
        s[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E) 
    {
        Edge next_edge = graph->e[i++];
        int x = find(s, next_edge.src);
        int y = find(s, next_edge.dest);
 
        if (x != y) {
            result[e++] = next_edge;
            Union(s, x, y);
        }
    }
    cout << "Cac canh toi thieu: "<<endl;
    int Minimum = 0;
    for (i = 0; i < e; ++i) 
    {
        cout << result[i].src << " -- " << result[i].dest
             << " == " << result[i].weight << endl;
        Minimum = Minimum + result[i].weight;
    }
     cout << "Tong cac canh toi thieu: " << Minimum << endl;
}
int main()
{
    int V = 4; // số đỉnh
    int E = 5; // số cạnh
    Graph* g = createGraph(V, E);
 
    // add edge 0-1
    g->e[0].src = 0;
    g->e[0].dest = 1;
    g->e[0].weight = 10;
 
    // add edge 0-2
    g->e[1].src = 0;
    g->e[1].dest = 2;
    g->e[1].weight = 6;
 
    // add edge 0-3
    g->e[2].src = 0;
    g->e[2].dest = 3;
    g->e[2].weight = 5;
 
    // add edge 1-3
    g->e[3].src = 1;
    g->e[3].dest = 3;
    g->e[3].weight = 15;
 
    // add edge 2-3
    g->e[4].src = 2;
    g->e[4].dest = 3;
    g->e[4].weight = 4;

    Kruskal(g);
    system("pause");
    return 0;
}