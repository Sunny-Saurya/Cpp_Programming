#include<bits/stdc++.h>

bool isCycle(int node,unordered_map<int, bool>&visited,unordered_map<int, bool>&dfsVisited, unordered_map<int, list<int>>&adj){
  visited[node] = 1;
  dfsVisited[node] =1;

  for(auto i : adj[node]){
    if(!visited[i]){
      bool ans1 = isCycle(i, visited, dfsVisited, adj);
      if(ans1) return true;
    }

    else if(dfsVisited[i]){
      return true;
    }
  }


  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  // creating adjacency list

  unordered_map<int, list<int>>adj;

  for(int i = 0; i < edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  // for all disconnected nodes

  unordered_map<int, bool>visited;
  unordered_map<int, bool>dfsVisited;

  for(int i = 1; i <=n; i++){
    if(!visited[i]){
      bool ans = isCycle(i, visited, dfsVisited, adj);
      if(ans){
        return true;
      }
    }
  }
  return false;
}