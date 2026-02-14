#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>adj;

void addEdge(int u , int v, int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u, w});
}

vector<int>shortestDistance(vector<vector<pair<int,int>>>&adj, int node, int n, int m){
    // make min - heap = {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int>dist(n, INT_MAX);
    pq.push({0, node});
    dist[node] = 0;

    while(!pq.empty()){
        int nodeDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto nei : adj[node]){

            int neiNode = nei.first;   // neighbour
            int neiDist = nei.second;  // weight

            int newDist = nodeDist + neiDist;

            if(newDist < dist[neiNode]){
                dist[neiNode] = newDist;
                pq.push({newDist, neiNode});
            }
        }
    }
    return dist;
}

int main(){
    int n;
    // cout << "Number of nodes : " << endl;
    cin >> n;

    int m;
    // cout << " NUmber of edges : " << endl;
    cin >> m;

    adj.resize(n);

    for(int i = 0; i < m    ; i++){
        int u, v, w;
        cin >> u >> v >> w;

        addEdge(u, v, w);
    }
    int src = 0;
    vector<int>dist = shortestDistance(adj, src, n, m);
    for(int i = 0; i < dist.size(); i++){
        cout << dist[i] << " ";
    }
}