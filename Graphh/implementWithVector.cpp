#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:

    int n;
    vector<vector<int>> ans; // putting all the neighbour element
    vector<vector<int>> adj;

    Graph(int node){
        n = node;
        ans.resize(n);
        adj.resize(n);
    }

    void addEdges(int u, int v, bool direction){
        ans[u].push_back(v);

        if(direction == 0){
            ans[v].push_back(u);
        }
    }

    void addEdgesToAdj(){
        for(int i = 0; i < n; i++){
            adj[i].push_back(i);

            for(int j = 0; j < ans[i].size(); j++){
                adj[i].push_back(ans[i][j]);
            }
        }
    }

    void printList(){
        cout << "Adjacency List: "<< endl;

        for(int i = 0; i < n; i++){
            cout << adj[i][0] << " --> ";

            for(int j = 0; j < adj[i].size(); j++){
                cout << adj[i][j] << ",";
            }
            cout << endl;
        }
    }

};

int main(){
    
    
    int node;
    cout << "Enter the number of nodes : ";
    cin >> node;

    int edge;
    cout << "Enter the number of edges : ";
    cin >> edge;

    Graph g(node);

    for(int i = 0; i < edge; i++){
        int u, v;

        cin >> u >> v;
        g.addEdges(u, v, 0);
    }
    g.addEdgesToAdj();
    g.printList();
}