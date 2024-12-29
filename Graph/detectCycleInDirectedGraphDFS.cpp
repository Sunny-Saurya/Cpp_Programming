#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    void addEdges(int u, int v)
    {
        // directed;
        adj[u].push_back(v);
    }

    void printAdj(){
        for(auto &i: adj){
            cout<<i.first<<" -> ";
            for(auto &j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    bool checkCycleDFS(int node){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto &neighbour : adj[node]){
            if(!visited[neighbour]){
                if(checkCycleDFS(neighbour)){
                    return true; // cycle found
                }
            }
            else if(dfsVisited[neighbour]){
                return true; // cycle found
            }
        }
        dfsVisited[node] = false;
        return false;
    }

    bool detectCycle(){
        for(auto &node : adj)
        {
            if(!visited[node.first]){
                if(checkCycleDFS(node.first)){
                    return true;
                }
            }
        }
        return false; // no cycle detected
    }

    
};

int main()
{
    int n;
    cout << "Enter number of node: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    Graph g;
    for(int i = 0; i < m; i++){
        int u, v;
        cout << "Enter edge " << i+1 << " : ";
        cin >> u >> v;
        g.addEdges(u, v);
    }
    cout << "Adjcency List is : ";
    g.printAdj();

    // Detect cycle

    if(g.detectCycle()){
        cout << "Graph contains cycle" << endl;
    }
    else{
        cout << "Graph does not contain cycle" << endl;
    }
    return 0;


}