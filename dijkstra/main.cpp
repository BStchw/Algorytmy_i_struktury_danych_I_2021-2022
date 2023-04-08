#include <iostream>
#include <cassert>
#include "dijkstra.h"
#include "graph.h"

using namespace std;

int main()
{
    // stworzenie grafu
    int V = 10;
    struct Graph graph = Graph(V);
    Graph *graph1 = &graph;
    graph.addEdge(0, 1, 4);
    graph.addEdge(1, 2, 30);
    graph.addEdge(0, 3, 1);
    graph.addEdge(3, 4, 9);
    graph.addEdge(2, 5, 8);
    graph.addEdge(5, 6, 4);
    graph.addEdge(2, 8, 3);
    graph.addEdge(8, 7, 2);
    graph.addEdge(3, 9, 10);
    graph.addEdge(2, 3, 7);
    graph.addEdge(0, 6, 5);


    int wyniki[V];
    dijkstra(graph1, 0, wyniki);

    
    printArr(wyniki, V);


    return 0;
}