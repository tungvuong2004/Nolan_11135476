
// Name: Nolan
 // Student ID: 1113543
 // Date of Submission: 2024/12/12


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of vertices (V) and edges (E)
    int V, E;
    cin >> V >> E;

    // Initialize adjacency list
    vector<vector<int>> adjList(V);

    // Read all edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // Since the graph is undirected, add both ways
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Sort the adjacency lists
    for (int i = 0; i < V; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    // Print the adjacency list in the desired format
    cout << "[";
    for (int i = 0; i < V; i++) {
        cout << "[";
        for (int j = 0; j < (int)adjList[i].size(); j++) {
            cout << adjList[i][j];
            if (j < (int)adjList[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < V - 1) cout << ",";
    }
    cout << "]\n";

    return 0;
}
