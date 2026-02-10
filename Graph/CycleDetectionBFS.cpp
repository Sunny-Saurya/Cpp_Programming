#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    void addEdge(int u, int v, int direction)
    {
        // direction - 0 -> undirected, 1 -> directe d

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

    bool isCyclicBFS(int src)
    {
        unordered_map<int, int> parent;
        parent[src] = -1;
        visited[src] = 1;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto i : adj[front])
            {
                if (visited[i] && i != parent[front])
                {
                    return true;
                }
                else if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = front;
                }
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
                if (isCyclicBFS(i.first))
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

// time complexity -> O(n);
// space complexity -> O(n);
