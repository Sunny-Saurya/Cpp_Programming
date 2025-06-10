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

    bool isCycle(int node,unordered_map<int, bool>&visited, unordered_map<int, bool>&dfsVisited, unordered_map<int,list<int>>&adj){
        visited[node] = 1;
        dfsVisited[node] = 1;

        for(auto i : adj[node]){
            if(!visited[i]){
                bool ans = isCycle(i, visited, dfsVisited, adj);
                if(ans) return true;
            }
            else if(dfsVisited[i]){
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }

    string detectCycleInDirectedGraph(int n, int m){
        unordered_map<int, bool>visited;
        unordered_map<int, bool>dfsVisited;

        for(int i =0 ; i < n; i++){
            if(!visited[i]){
                bool ans = isCycle(i, visited, dfsVisited, adj);

                if(ans) return "Yes";
            }
        }
        return "No";
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

        g.addEdge(u, v, 1);
    }

    g.printList();

    cout << "Cycle is present (Yes / No) : " << g.detectCycleInDirectedGraph(n, e);


}