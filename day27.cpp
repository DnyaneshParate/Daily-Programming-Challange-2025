/*
  Question :- 
  Find the Shortest Path in an Unweighted Graph You are given an unweighted graph represented by an adjacency list. 
  Your task is to find the shortest path (in terms of the number of edges) between two given nodes in the graph.
*/

// Code : - 
#include <bits/stdc++.h>
using namespace std;

int shortestPath(int V, vector<pair<int, int>> &edges, int start, int end) {
    vector<vector<int>> graph(V);
    for (auto &edge : edges) {
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(V, false);
    queue<pair<int, int>> q;

    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (node == end) return dist;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}
    };
    int start = 0, end = 4;

    cout << shortestPath(V, edges, start, end) << endl;
    return 0;
}
