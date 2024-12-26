#include<bits/stdc++.h>
using namespace std;

class Graph{
     public:
     unordered_map<int, list<int>> adj;

     void addEdges(int u, int v, bool direction)
     {
        // direction 0 --> undirected graph
        // direction 1 --> directed graph

        // Create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0)
        {
            // create an edge from v to u
            adj[v].push_back(u);
        }

     }

     void printAdjList()
     {
        for(auto i : adj)
        {
            cout << i.first << " -> ";
            for(auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
     }
    
};

int main()
{

    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    int a;
    cout << "Enter number of edges : ";
    cin >> a;

    Graph g;

    for(int i = 0; i < a; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating undirected graph
        g.addEdges(u, v, 0);
    }

    // printing graph
    g.printAdjList();
    return 0;

}