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

    void printList(){
        for(auto i : adj){
                cout << i.first << " --> ";
            for(auto j : i.second){
                cout << j << " ,";
            }
            cout << endl;
        }
    }

    bool kahnSorting(int n, int e){
        queue<int>q;
        vector<int> indegree(n+1);

        // find the inderee for the nodes

        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++;
            }
        }

        // node which have 0 degree push it on queue
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        // do bfs

        int count = 0;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            count++;
            // visti neighbour

            for(auto i : adj[frontNode]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }   

       return count == n;

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

        g.addEdges(u, v, 1);
    }

    g.printList();

    if(g.kahnSorting(n, e)){
        cout << "Cycle is Not there !!";
    }
    else{
        cout << "Cycle is Present there !!";
    }
    
}