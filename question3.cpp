/*
  Name: Nolan
  Student ID: 1113543
  Date of Submission: 2024-12-12
*/

#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfsOrder) {
    visited[node] = true;
    dfsOrder.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited, dfsOrder);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of vertices
    int V; cin >> V;
    vector<vector<int>> adj(V);

    // Reading adjacency list:
    // For each vertex i:
    // First read k = number of neighbors, then read those k neighbors
    for (int i = 0; i < V; i++) {
        int k; cin >> k;
        adj[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> adj[i][j];
        }
    }

    // Prepare for DFS traversal
    vector<bool> visited(V, false);
    vector<int> dfsOrder;

    // Start DFS from vertex 0
    dfsUtil(0, adj, visited, dfsOrder);

    // Print the DFS order
    cout << "[";
    for (int i = 0; i < (int)dfsOrder.size(); i++) {
        cout << dfsOrder[i];
        if (i < (int)dfsOrder.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}

