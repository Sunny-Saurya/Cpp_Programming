#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:

    // first we have to create adjacency matrix

    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction)
    {
        // 0 -> undirected graph
        // 1 -> directed graph

        adj[u].push_back(v);
        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdj()
    {
        for(auto i : adj)
        {
            cout << i.first << " -> ";
            for(auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }


};

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of Edges: ";
    cin >> m;

    Graph g;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter edge (u, v): ";
        cin >> u >> v;

        g.addEdge(u, v, 0); // 0 for undirected graph
    }
    cout << endl;
    cout << "The adjacency list of the graph is: " << endl;
    g.printAdj();
    return 0;
}
