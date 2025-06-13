#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    unordered_map<int, list<int>>adj;

    void addEdges(int u, int v, int direction){
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    // printing list

    void printList(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ,";
            }
            cout << endl;
        }
    }

    // finding shortest parth in undirected graph

    vector<int> shortestPath(int src, int t,int n, int e){

        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        visited[src] = 1;
        parent[src] = -1;
        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto i: adj[frontNode]){
                if(!visited[i]){
                    visited[i] = 1;
                    parent[i] = frontNode;
                    q.push(i);
                }
            }
        }

        int currentNode = t;
        vector<int> ans;
        ans.push_back(t);

        while (currentNode != src)
        {
            currentNode = parent[currentNode];
            ans.push_back(currentNode);
        }
        

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    Graph g;

    int n;
    cout << "Enter Number of Node: ";
    cin >> n;

    int e;
    cout << "Enter numebr of edges : ";
    cin >> e;

    int s;
    cout << "Enter Source Node: ";
    cin >> s;

    int t;
    cout<< "Enter Destination Node: ";
    cin >>t;

    for(int i = 0; i < e; i++){
        int u,v;
        cin>> u >> v;

        g.addEdges(u, v, 0);
    }
    cout << "The Adjacency List : ";
    g.printList();


    cout << "The  shortest path is : ";
    vector<int>result = g.shortestPath(s,t,n,e);

    for(auto i : result){
        cout << i << " ";
    }

}
