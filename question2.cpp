 //Name: Nolan
 // Student ID: 1113543
 // Date of Submission: 2024/12/12

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of vertices
    int V; 
    cin >> V;

    // Reading the adjacency list:
    // Format: For each of the V lines:
    // First integer = number of neighbors (k), followed by k neighbors.
    vector<vector<int>> adj(V);
    for (int i = 0; i < V; i++) {
        int k; cin >> k;
        adj[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> adj[i][j];
        }
    }

    // Perform BFS from vertex 0
    vector<int> bfsOrder;
    vector<bool> visited(V, false);
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        bfsOrder.push_back(current);

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

  
    cout << "[";
    for (int i = 0; i < (int)bfsOrder.size(); i++) {
        cout << bfsOrder[i];
        if (i < (int)bfsOrder.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}

