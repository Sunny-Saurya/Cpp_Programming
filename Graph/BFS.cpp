#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>>adj;
    unordered_map<int, bool>visited;
    vector<int>ans;

    void addEdges(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bfs(){
        queue<int>q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);
            for(auto i : adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        
    }

    void printEdges(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ,";
            }
            cout << endl;
        }
    }

     void printBFS() {
        for (int node : ans) {
            cout << node << " ";
        }
        cout << endl;
    }




};

int main(){
    int n;
    cout << "Enter the number of node : ";
    cin  >> n;

    int m;
    cout << " Enter the number of edges : ";
    cin >> m;

    Graph g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdges(u, v);
    }
    g.printEdges();
   
    g.bfs();
}