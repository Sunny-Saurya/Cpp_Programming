#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    
    unordered_map<int, list<pair<int,int>>> adj;
    
    void addEdges(int u, int v, int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void printGraph()
    {
        for(auto &i: adj){
            cout<<i.first<<"->";
            for(auto &j: i.second){
                cout<< "(" <<j.first<<" "<<j.second<<") ";
            }
            cout<<endl;
        }
    }

    void primsAlgo(int src, int n)
    {
        vector<int>  key(n+1);
        vector<bool> mst(n+1);
        vector<int> parent(n+1);

        for(int i = 0; i < n; i++)
        {
            key[i] = INT_MAX;
            mst[i] = false;
            parent[i] = -1;
        }

        // starting node 
        key[src] = 0;
        parent[src] = -1;

        for(int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            int u;

            for(int j = 0; j < n; j++)
            {   
                if(mst[j] == false && key[j] < mini)
                {
                    u = j;
                    mini = key[j];
                }
            }

            // mark node u as visited
            mst[u] = true;
            

            // traverse to its adjacent nodes

            for(auto neighbor : adj[u])
            {
                int v = neighbor.first;
                int w = neighbor.second;
                if(mst[v] == false && w < key[v]){
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        // printing of mst
        int totalWeight = 0;
        for(int i = 1; i < n; i++){
            cout << src << " - " << i << " : " << key[i] << endl
            << "Parent of " << i << " is " << parent[i] << endl;
            totalWeight += key[i];
        }
        cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    Graph g;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cout << "Enter edge " << i+1 << " details (u v w) : ";
        cin >> u >> v >> w;
        g.addEdges(u, v,w);
    }
    cout << "printing adjacency list representation of graph" << endl;
    g.printGraph();

    int src;
    cout << "Enter the source node : ";
    cin >> src;

    g.primsAlgo(src, n);
}