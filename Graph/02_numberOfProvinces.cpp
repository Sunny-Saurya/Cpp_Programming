// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node, vector<vector<int>>&adj, int V, vector<int>&vis){
        vis[node] = 1;
        for(int i =0 ; i < V; i++){
            if(!vis[i] &&  adj[node][i] == 1){
                dfs(i, adj, V, vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int prov = 0;
        vector<int>vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                prov++;
                dfs(i, adj,V, vis);
            }
        }
        return prov;
        
    }
};