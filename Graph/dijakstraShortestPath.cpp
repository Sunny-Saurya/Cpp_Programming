#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    // Adjacency list representation
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdges(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void printAdjacencyList() {
        for (auto &i : adj) {
            cout << i.first << " -> ";
            for (auto &j : i.second) {
                cout << "(" << j.first << " " << j.second << ") ";
            }
            cout << endl;
        }
    }

    void dijkstra(int src, int n) {
        // Distance array
        vector<int> dist(n, INT_MAX);

        // Set to store (distance, node)
        set<pair<int, int>> s;

        // Initialize source
        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty()) {
            // Fetching the top node
            auto top = *s.begin();
            int nodeDist = top.first;
            int node = top.second;

            // Deleting the top node
            s.erase(top);

            // Iterate over neighbors
            for (auto &neighbor : adj[node]) {
                int neighborNode = neighbor.first;
                int weight = neighbor.second;

                // Relaxation
                int newDist = nodeDist + weight;
                if (newDist < dist[neighborNode]) {
                    // Remove the old record if it exists
                    auto record = s.find({dist[neighborNode], neighborNode});
                    if (record != s.end()) {
                        s.erase(record);
                    }

                    // Update distance and insert new record
                    dist[neighborNode] = newDist;
                    s.insert({dist[neighborNode], neighborNode});
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) {
                cout << "Node " << i << ": Unreachable\n";
            } else {
                cout << "Node " << i << ": " << dist[i] << "\n";
            }
        }
    }
};

int main() {
    Graph g;
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Enter edge " << i + 1 << " details (u v w): ";
        cin >> u >> v >> w;
        g.addEdges(u, v, w);
    }

    cout << "Printing Adjacency List:\n";
    g.printAdjacencyList();

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    g.dijkstra(src, n);

    return 0;
}
