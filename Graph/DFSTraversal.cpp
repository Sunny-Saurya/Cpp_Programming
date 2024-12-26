#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    void addEdge(int u, int v, int direction) {
        // direction 0 -> undirected
        // direction 1 -> directed

        adj[u].push_back(v); // Corrected: Add edge u -> v

        if (direction == 0) {
            adj[v].push_back(u); // Add edge v -> u for undirected graph
        }
    }

    void dfs(int startNode) {
        visited[startNode] = true;
        cout << startNode << " ";
        
        for (auto &it : adj[startNode]) {
            if (!visited[it]) {
                dfs(it);
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    Graph g;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // Undirected graph
    }

    cout << "DFS Traversal: ";
    for (int i = 0; i < n; i++) {
        if (!g.visited[i]) {
            g.dfs(i); // Call DFS for unvisited nodes
        }
    }

    return 0;
}
