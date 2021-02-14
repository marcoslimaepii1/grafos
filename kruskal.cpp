// C++ program for Kruskal's algorithm to find Minimum Spanning Tree  
// of a given connected, undirected and weighted graph  
#include <bits/stdc++.h> 
using namespace std; 
  
// a structure to represent a weighted edge in graph  
class Edge  
{  
    public: 
    int src, dest, weight;  
};  
  
// a estrutura que vai representar o grafo

class Graph  
{  
    public: 
    // V->Numero de vertices, E-> numero de arestas  
    int V, E;  
    Edge* edge;  
};  
  
// função para criar um grafo 
Graph* createGraph(int V, int E)  
{  
    Graph* graph = new Graph;  
    graph->V = V;  
    graph->E = E;  
  
    graph->edge = new Edge[E];  
  
    return graph;  
}  
  
class subset  
{  
    public: 
    int parent;  
    int rank;  
};  
  
// função find
int find(subset subsets[], int i)  
{  
    if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}  
  
// A function that does union of two sets of x and y  
// (uses union by rank)  
void Union(subset subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);  
  
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  
   
    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}  
   
int myComp(const void* a, const void* b)  
{  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->weight > b1->weight;  
}  
  

// Algoritmo de kruskal  
void KruskalMST(Graph* graph)  
{  
    int V = graph->V;  
    Edge result[V]; 
    int e = 0;  
    int i = 0; 
  

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);  
  
    // Aloca na memória
    subset *subsets = new subset[( V * sizeof(subset) )];  
  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  
  
   
    while (e < V - 1 && i < graph->E)  
    {  
        Edge next_edge = graph->edge[i++];  
  
        int x = find(subsets, next_edge.src);  
        int y = find(subsets, next_edge.dest);  
  
        if (x != y)  
        {  
            result[e++] = next_edge;  
            Union(subsets, x, y);  
        }  
    }  
  
    //imprime o resultado do algoritmo 
    for (i = 0; i < e; ++i)  
        cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;  
    return;  
}  
   
int main()  
{  

   int V = 0;
   int E = 0;

   cin >> V >> E;

   Graph* graph = createGraph(V, E);  
  
	// Lendo o arquivo
	for(int t=0; t<E; ++t) {
	    int a, b, c;
	    cin >> a >> b >> c;
	    graph->edge[t].src = a;  
	    graph->edge[t].dest = b;  
	    graph->edge[t].weight = c; 
	}
  
    KruskalMST(graph);  
  
    return 0;  
}  
