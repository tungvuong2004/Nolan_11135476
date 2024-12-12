/*
  Name: Nolan
  Student ID: 1113543
  Date of Submission: 2024-12-12
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n,0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findSet(int x) {
        return (parent[x] == x) ? x : (parent[x] = findSet(parent[x]));
    }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a,b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    UnionFind uf(V);
    int mstWeight = 0;
    int edgesUsed = 0;

    for (auto &edge : edges) {
        if (uf.unionSet(edge.u, edge.v)) {
            mstWeight += edge.w;
            edgesUsed++;
            if (edgesUsed == V - 1) break;
        }
    }

    cout << mstWeight << "\n";

    return 0;
}

