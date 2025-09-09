/*
  Question :- 
Detect a Cycle in an Undirected Graph
You are given an undirected graph represented by an adjacency list. Your task is to determine if the graph contains any cycle.
A cycle is formed if you can traverse through a sequence of edges that starts and ends at the same vertex, with at least one edge in between.

*/

//Code :- 
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCyclicUtil(int v, vector<bool>& visited, int parent) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, v))
                    return true;
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool containsCycle() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    Graph g(V);
    for (auto e : edges) {
        g.addEdge(e[0], e[1]);
    }
    if (g.containsCycle())
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}
