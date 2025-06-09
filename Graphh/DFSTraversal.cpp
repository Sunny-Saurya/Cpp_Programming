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

    void dfs(unordered_map<int, bool>&visited, vector<int>&ans, int node){
        ans.push_back(node);
        visited[node] = 1;

        for(auto i :adj[node]){
            if(!visited[i]){
                dfs(visited, ans, i);
            }
        }
    }

    vector<int> DFS(int node){
        unordered_map<int, bool>visited;
        vector<int> ans;

        for(int i = 0; i < node; i++){
            if(!visited[i]){
                dfs(visited, ans, i);
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

    vector<int> dfsResult = g.DFS(node);

    cout << "\nDFS Traversal: ";
    for (auto i : dfsResult) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}