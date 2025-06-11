#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v, int direction) {
        adj[u].push_back(v);

        if (direction == 0) { // Undirected graph
            adj[v].push_back(u);
        }
    }

    void printList() {
        for (auto i : adj) {
            cout << i.first << " --> ";
            for (auto j : i.second) {
                cout << j << " ,";
            }
            cout << endl;
        }
    }

    // Fix 1: Pass visited by reference
    void bfs(unordered_map<int, bool>& visited, vector<int>& ans, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);
            // for disconnected component in the same graph
            for (auto i : adj[frontNode]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    vector<int> BFS(int node) {
        unordered_map<int, bool> visited;
        vector<int> ans;

        for (int i = 0; i < node; i++) {
            if (!visited[i]) {
                bfs(visited, ans, i);
            }
        }

        // Fix 2: Return the result
        return ans;
    }
};

int main() {
    Graph g;
    int node;
    cout << "Enter the number of nodes: ";
    cin >> node;

    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdges(u, v, 0);
    }

    g.printList();

    vector<int> bfsResult = g.BFS(node);

    cout << "\nBFS Traversal: ";
    for (auto i : bfsResult) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
