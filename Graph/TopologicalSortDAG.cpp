#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v) {
        // Directed graph
        adj[u].push_back(v);
    }

    void printAdj() {
        for (auto &i : adj) {
            cout << i.first << " -> ";
            for (auto &j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s) {
        visited[node] = true;
        for (auto &i : adj[node]) {
            if (!visited[i]) {
                topoSort(i, visited, s);
            }
        }
        s.push(node);
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Adjacency list of graph is:\n";
    g.printAdj();

    unordered_map<int, bool> visited;
    stack<int> s;

    // Initialize visited for all nodes in the graph
    for (auto &i : g.adj) {
        visited[i.first] = false;
    }

    // Perform topological sort for all nodes in the graph
    for (auto &i : g.adj) {
        if (!visited[i.first]) {
            g.topoSort(i.first, visited, s);
        }
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    cout << "Topological Sort: ";
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
