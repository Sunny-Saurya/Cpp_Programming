#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void shortestPath(int s, int d)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;
        q.push(s);
        parent[s] = -1;
        visited[s] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto &neighbour : adj[front]){
                if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                    q.push(neighbour);
                }
            }
        }

        vector<int> ans;
        int currentNode = d;
        ans.push_back(currentNode);

        while(currentNode != s){
            currentNode = parent[currentNode];
            ans.push_back(currentNode);
        }

        reverse(ans.begin(), ans.end());
        cout<<"Shortest path from "<<s<<" to "<<d<<" is: ";
        for(auto i:ans){
            cout<<i<<" ";
        }
    }

};

int main()
{
    int n;
    cout << "Enter number of Nodes : " ;
    cin >> n;

    int m;
    cout << "Enter number of Edges : ";
    cin >> m;

    Graph g;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter edge " << i+1 << " : ";
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Adjacency List of Graph is : \n";
    g.printGraph();

    int source;
    cout << "Enter source node : ";
    cin >> source;

    int dest;
    cout << "Enter destination node : ";
    cin >> dest;

    g.shortestPath(source, dest);


}