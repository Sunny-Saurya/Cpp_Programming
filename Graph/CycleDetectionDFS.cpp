#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    void addEdge(int u, int v, int direction)
    {
        // direction - 0 -> undirected, 1 -> directed
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool isCyclicDFS(int node, int parent)
    {
        visited[node] = true;
        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (isCyclicDFS(neighbor, node))
                {
                    return true;
                }
            }
            else if (neighbor != parent)
            {
                // A cycle is detected
                return true;
            }
        }
        return false;
    }

    bool detectCycle()
    {
        // Reset visited map for all nodes
        visited.clear();
        for (auto i : adj)
        {
            if (!visited[i.first])
            {
                if (isCyclicDFS(i.first, -1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " : ";
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printAdj();

    if (g.detectCycle())
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
