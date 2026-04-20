#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // undirected graph
}

// BFS
void Graph::bfs(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }
    cout << endl;
}

// DFS
void Graph::dfsHelper(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            dfsHelper(neighbor.first, visited);
        }
    }
}

void Graph::dfs(int start) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfsHelper(start, visited);
    cout << endl;
}

// Dijkstra
void Graph::dijkstra(int start) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto neighbor : adj[node]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Dijkstra (Shortest distances from " << start << "):\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}