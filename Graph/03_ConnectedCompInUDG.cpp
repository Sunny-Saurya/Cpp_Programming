#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void solve(int node, vector<vector<int>>&res, int V, unordered_map<int, list<int>>&adj, vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        
        vector<int>ans;
        while(!q.empty()){
            auto node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto nei : adj[node]){
                if(!vis[nei]){
                    q.push(nei);
                    vis[nei] = 1;
                }
            }
            
        }
            res.push_back(ans);
        
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>>adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>res;
        vector<int>vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i])
                solve(i,res,V, adj, vis);
        }
        return res;
    }
};
