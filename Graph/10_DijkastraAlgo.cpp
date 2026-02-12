#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int>dist(V, 1e9);
        set<pair<int,int>>s;
        dist[src] = 0;
        s.insert({0, src});
        
        while(!s.empty()){
            auto top = *s.begin();
            int nodeDist = top.first;
            int node = top.second;
            s.erase(top);
            
            for(auto &nei: adj[node]){
                int neiNode = nei.first;
                int neiWeight = nei.second;
                
                int newDist = neiWeight + nodeDist;
                
                if(newDist < dist[neiNode]){
                    auto record = s.find({dist[neiNode], neiNode});
                    if(record != s.end()){
                        s.erase(record);
                    }
                    dist[neiNode] = newDist;
                    s.insert({dist[neiNode], neiNode});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e9) dist[i] = -1;
        }
        return dist;
        
        
    }
};