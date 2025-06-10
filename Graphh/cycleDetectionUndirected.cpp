#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    unordered_map<int,list<int>>adj;

    void addEdge(int u, int v, int direction){
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printList(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " , ";
            }
            cout <<endl;
        }
    }

    bool cycleDetection(int node,  unordered_map<int,bool> &visited){
        unordered_map<int, int> parent;
        parent[node] = -1;
        visited[node] = 1;

        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto i : adj[front]){
                if(visited[i] == true && i != parent[front]){
                    return true;
                }
                else if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = front;
                }
            }
        }
        return false;
    }

    string isCyclicUndirected(int n, int e){
        unordered_map<int,bool> visited;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bool ans = cycleDetection(i, visited);

                if(ans == 1){
                    return "Yes";
                }
            }
        }
        return "No";
    }
};

int main(){

    Graph g;

    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    int e;
    cout << "Enter numberr of edges : ";
    cin >> e;

    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    g.printList();

    cout << "Cycle is present (Yes / No) : " << g.isCyclicUndirected(n, e);


}