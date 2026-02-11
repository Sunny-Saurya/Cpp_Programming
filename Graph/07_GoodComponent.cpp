#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    
     bool solve(int start, unordered_map<int,list<int>>&adj, vector<int>&visited){
        queue<int>q; // {node,parent}
        q.push(start);
        visited[start] = 1;
        
        int nodes = 0;
        int edges = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            nodes++;
            edges += adj[node].size();
            
            for(auto nei : adj[node]){
                if(!visited[nei]){
                    visited[nei] = 1;
                    q.push(nei);
                }
            }
        }
            edges /= 2;
        return edges == (nodes * (nodes - 1))/2;
    }
  public:
    int findNumberOfGoodComponent(int e, int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>>adj;
        for(auto edge: edges){
            int u = edge[0] - 1;   // ✅ 1-based → 0-based
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>visited(V, 0);
        int count = 0;
        for(int i =0 ; i < V; i++){
            if(!visited[i]){
                if(solve(i,adj,visited)){
                    count++;
                }
            }
        }
        return count;
    }
};
