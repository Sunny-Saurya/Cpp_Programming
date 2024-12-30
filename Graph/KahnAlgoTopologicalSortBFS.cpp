#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v) {
        // Directed graph
        adj[u].push_back(v);
    }

    void printGraph() {
        for (auto &i : adj) {
            cout << i.first << " -> ";
            for (auto &j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    vector<int> topoSort(int n) {
        // Step 1: Calculate in-degrees of all nodes
        unordered_map<int, int> inDegree;
        for (auto &i : adj) {
            for (auto &j : i.second) {
                inDegree[j]++;
            }
        }

        // Initialize all nodes in inDegree map to 0
        for (int i = 0; i < n; i++) {
            if (inDegree.find(i) == inDegree.end()) {
                inDegree[i] = 0;
            }
        }

        // Step 2: Push all nodes with in-degree 0 into the queue
        queue<int> q;
        for (auto &i : inDegree) {
            if (i.second == 0) {
                q.push(i.first);
            }
        }

        // Step 3: Perform BFS-like traversal
        vector<int> result;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            result.push_back(front);

            for (auto &neighbor : adj[front]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the result size is less than the number of nodes, there is a cycle.
        if (result.size() < n) {
            cout << "Cycle detected in the graph. Topological sort not possible." << endl;
            return {};
        }

        return result;
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

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        g.addEdges(u, v);
    }

    cout << "Adjacency list of graph:\n";
    g.printGraph();

    vector<int> ans = g.topoSort(n);

    if (!ans.empty()) {
        cout << "Topological sort of the graph: ";
        for (auto &i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
