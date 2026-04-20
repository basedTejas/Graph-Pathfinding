#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj; // (node, weight)

public:
    Graph(int V);
    void addEdge(int u, int v, int w);

    void bfs(int start);
    void dfs(int start);
    void dijkstra(int start);

private:
    void dfsHelper(int node, vector<bool>& visited);
};

#endif