#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool solve(int start, unordered_map<int,list<int>>&adj, vector<int>&visited){
        queue<pair<int,int>>q; // {node,parent}
        q.push({start, -1});
        visited[start] = 1;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int node = it.first;
            int parent = it.second;
            
            for(auto nei : adj[node]){
                if(!visited[nei]){
                    visited[nei] = 1;
                    q.push({nei, node});
                    
                }
                else if(nei != parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,list<int>>adj;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>visited(V, 0);

        for(int i =0 ; i < V; i++){
            if(!visited[i]){
                if(solve(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};