#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {

    unordered_map<int, list<pair<int, int>>> adj;

    // Building the adjacency list
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> MST(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[1] = 0; // starting from node 1
    parent[1] = -1;

    for (int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        int u = -1;

        // Selecting minimum key value vertex not yet included in MST
        for (int j = 1; j <= n; j++) {
            if (!MST[j] && key[j] < mini) {
                mini = key[j];
                u = j;
            }
        }

        if (u == -1) break; // if the graph is disconnected

        MST[u] = true;

        // Relaxing adjacent vertices
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (!MST[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++) { // starting from 2 because 1 is the source
        if (parent[i] != -1) {
            result.push_back({{parent[i], i}, key[i]});
        }
    }

    return result;
}

int main() {

    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<pair<pair<int, int>, int>> edges;

    cout << "Enter edges in the format (u v w): " << endl;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    cout << "\nMinimum Spanning Tree edges:" << endl;
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}
