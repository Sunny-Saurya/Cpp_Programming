#include<bits/stdc++.h>


class Graph {

    // 1st APPROACH USING DFS
//     private:

//     bool dfs(int node, int parent, unordered_map<int, bool>&visited, vector<int>adj[]){
//         visited[node] = 1;

//         for(auto i : adj[node]){
//             if(!visited[i]){
//                 bool ans = dfs(i, node, visited, adj);
//                 if(ans) return true;
//             }
//             else if(i != parent){
//                 return true;
//             }
//         }
//         return false;
//     }

// public:
//     bool detectCycle(int V, vector<int> adj[]) {
//         // Write your code here.
//         unordered_map<int,bool>visited;

//         for(int i = 0; i < V; i++){
//             if(!visited[i]){
//                 bool cycleFound = dfs(i, -1, visited, adj);
//                 if(cycleFound) return true;
//             }
//         }
//         return false;
//     }


    // 2ND AND BEST APPROACH USING BFS

    private:

    bool bfs(int node, unordered_map<int, bool>&visited, unordered_map<int,int>&parent, vector<int>adj[]){
        visited[node] = 1;
        parent[node] = -1;

        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto i : adj[frontNode]){
                if(!visited[i]){
                    visited[i] = 1;
                    parent[i] = frontNode;
                    q.push(i);
                }
                else if(i != parent[frontNode]){
                    return true;
                }
            }
        }
        return false;
    }

    public:

    bool detectCycle(int V, vector<int> adj[]){
        unordered_map<int,bool>visited;
        unordered_map<int, int> parent;

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool ans = bfs(i, visited, parent, adj);
                if(ans) return true;
            }
        }
        return false;
    }



};