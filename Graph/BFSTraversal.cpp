#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    vector<int> ans;

    void addEdge(int u, int v, bool direction)
    {
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

    void bfs(int startNode)
    {
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto neighbor : adj[frontNode])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter edge (u, v): ";
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    cout << endl;
    cout << "The adjacency list of the graph is: " << endl;
    g.printAdj();

    cout << endl;
    cout << "BFS Traversal of the graph is: ";

    // Perform BFS for all nodes to handle disconnected components
    for (int i = 0; i < n; i++)
    {
        if (!g.visited[i])
        {
            g.bfs(i);
        }
    }

    for (auto node : g.ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
