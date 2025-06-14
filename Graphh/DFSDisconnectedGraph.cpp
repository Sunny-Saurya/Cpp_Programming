#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    unordered_map<int, list<int>>adj;

    void addEdges(int u, int v, int direction){
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void dfs(unordered_map<int, bool>&visited, vector<int>&component, int node){
        component.push_back(node);
        visited[node] = 1;

        for(auto i :adj[node]){
            if(!visited[i]){
                dfs(visited, component, i);
            }
        }
    }

    vector<vector<int>> DFS(int node){
        unordered_map<int, bool>visited;
        vector<vector<int>>ans;

        for(int i = 0; i < node; i++){
            vector<int>component;

            if(!visited[i]){
                dfs(visited, component, i);
                ans.push_back(component);
            }
        }

        return ans;
    }
};

int main(){
    Graph g;
    int node;
    cout << "Enter the number of nodes: ";
    cin >> node;

    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdges(u, v, 0);
    }

    // g.printList();

   vector<vector<int>> dfsResult = g.DFS(node);

cout << "\nDFS Traversal: ";
for (auto component : dfsResult) {  // for each connected component
    for (auto node : component) {   // for each node in that component
        cout << node << " ";
    }
    cout << "| ";  // separator between components (optional)
}
cout << endl;


    return 0;
}