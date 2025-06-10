#include <bits/stdc++.h> 

void topoSort(int node, vector<bool>&visited, stack<int>&s, unordered_map<int,list<int>>&adj){
    visited[node] = 1;

    for(auto i: adj[node]){
        if(!visited[i]){
            topoSort(i, visited,s, adj);
        }
    }
    s.push(node);

}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    unordered_map<int, list<int>>adj;
    for(int i = 0; i < edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int>s;

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}