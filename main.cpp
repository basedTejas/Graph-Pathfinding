#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    int V = 5;
    Graph g(V);

    // Sample Graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    int start = 0;

    g.bfs(start);
    g.dfs(start);
    g.dijkstra(start);

    return 0;
}