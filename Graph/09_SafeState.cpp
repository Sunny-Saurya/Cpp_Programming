#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // making adjacency list

        int V = graph.size();
        unordered_map<int, list<int>>adj;
        vector<int>indegree(V, 0);

        // we are changing the arrow or indegree to outdegree

        for(int i = 0; i < V; i++){
            for(auto j : graph[i]){
                adj[j].push_back(i);
                indegree[i]++;
            }
        }   

        // making indegree  array

        vector<int>topo;
        queue<int>q;

        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            topo.push_back(frontNode);

            for(auto i : adj[frontNode]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};