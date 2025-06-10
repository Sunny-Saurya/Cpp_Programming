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

    void topoSort(int node, vector<bool>&visited, stack<int>&s){
        visited[node] = 1;

        for(auto i : adj[node]){
            if(!visited[i]){
                topoSort(i, visited, s);
            }
        }
        s.push(node);
    }

    vector<int> topologicalSort(int n, int e){
        vector<bool>visited(n);
        stack<int>s;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                topoSort(i, visited, s);
            }
        }

        vector<int> ans;

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
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

    vector<int>ans = g.topologicalSort(n, e);
    cout << "THe Topologica sort of this graph is : ";
    for(auto i : ans){
        cout << i << " ";
    }


}