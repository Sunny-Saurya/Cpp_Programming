#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    unordered_map<int,list<int>>adj;

    void addEdge(int u, int v, int direction){
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printList(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " , ";
            }
            cout <<endl;
        }
    }

    bool cyclePresent(int node, int parent,unordered_map<int, bool>&visited){
        visited[node] = 1;

        for(auto i : adj[node]){
            if(!visited[i]){
                bool ans = cyclePresent(i, node, visited);
                if(ans){
                    return true;
                }
            }
            else if(i != parent){
                return true;
            }
        }
        return false;
    }

    string isCyclicUndirected(int n, int e){
        unordered_map<int, bool>visited;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bool ans = cyclePresent(i, -1, visited);

                if(ans){
                    return "Yes \n";
                }
            }
        }
        return "No\n";
    }
};

int main(){

    Graph g;

    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    int e;
    cout << "Enter numberr of edges : ";
    cin >> e;

    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    g.printList();

    cout << "Cycle is present (Yes / No) : " << g.isCyclicUndirected(n, e);


}