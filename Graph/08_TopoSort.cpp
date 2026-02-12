#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>>adj;

void addEdge(int u , int v){
    adj[u].push_back(v);
}

void printAdj() {
        for (auto &i : adj) {
            cout << i.first << " -> ";
            for (auto &j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

void topoSort(int node, unordered_map<int,int>&vis, stack<int>&s){
    vis[node] = 1;
    for(auto nei : adj[node]){
        if(!vis[nei]){
            vis[nei] = 1;
            topoSort(nei, vis, s);
        }
    }
    s.push(node);
}
int main(){
    int n;
    // cout << "Number of nodes : " << endl;
    cin >> n;

    int m;
    // cout << " NUmber of edges : " << endl;
    cin >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        addEdge(u, v);
    }

    unordered_map<int,int>vis;
    for (auto &i : adj) {
        vis[i.first] = false;
    }
    stack<int>s;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = 1;
            topoSort(i, vis, s);
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}