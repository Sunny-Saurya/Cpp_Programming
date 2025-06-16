// find articulation point : it is the point or node by removing it the graph will be becaome disconnected and have more than one components;


#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool>&visited, vector<int>&ap,unordered_map<int, list<int>>&adj, int &timer){

    visited[node] = 1;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto i : adj[node]){
        if(i == parent){
            continue;
        }

        if(!visited[i]){
            dfs(i, node, disc, low, visited, ap, adj, timer);
            low[node] = min(low[node], low[i]);

            // check if Ap Or not

            if(low[i] >= disc[i] && parent != 1){
                ap[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node], low[i]);
        }
    }

    if(parent == -1 && child > 1){
        ap[node] = 1;
    }

}

int main(){

    int n = 5;
    int e = 5;

    vector<pair<int, int>>edges;
    edges.push_back({0,3});
    edges.push_back({3,4});
    edges.push_back({0,4});
    edges.push_back({0,1});
    edges.push_back({1,2});


    unordered_map<int, list<int>>adj;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> visited;
    vector<int> ap(n,0);
    int timer = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, -1, disc, low, visited, ap, adj, timer);
        }
    }

    cout << "The articulation node is/are : ";

    for(int i = 0; i < ap.size(); i++){
        if(ap[i] != 0){
            cout << i << " ";
        }
    }
    cout << endl;

}