#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdges(int u, int v, int w){
        pair<int,int> p = make_pair(v, w);
        adj[u].push_back(p);
    }

    void printList(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << "( " << j.first << ", " << j.second << " ) ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int>& s){
        visited[node] = 1;

        for(auto i : adj[node]){
            if(!visited[i.first]){
                dfs(i.first, visited, s);
            }
        }
        s.push(node);
    }

    void topologicalSort(int src, int n){
        unordered_map<int, bool> visited;
        stack<int> s;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, s);
            }
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!s.empty()){
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX){
                cout << i << " -> INF" << endl;
            } else {
                cout << i << " -> " << dist[i] << endl;
            }
        }
    }
};

int main(){
    Graph g;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    cout << "Enter edges in the format: u v w\n";
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdges(u, v, w);
    }

    cout << "\nThe Adjacency List:\n"; 
    g.printList();

    cout << "\nTopological Sort and Shortest Distances:\n";
    g.topologicalSort(src, n);

    return 0;
}
