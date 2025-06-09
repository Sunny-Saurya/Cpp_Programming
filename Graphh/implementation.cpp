#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    map<int, list<int>> adj;

    void addEdges(int u, int v, bool direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printList(){
        for(auto i: adj){
            cout << i.first << "->";
            for(auto j : i.second){
                cout << j << ",";
            }
        cout << endl;
        }
    }
};

int main()
{
    Graph g;
    int node;
    cout << "Enter the number of nodes : ";
    cin >> node;

    int edge;
    cout << "Enter the number of edges : ";
    cin >> edge;

    for(int i = 0; i < edge; i++){
        int u, v;
        cin >> u >> v;

        g.addEdges(u, v, 0);
    }

    g.printList();
}