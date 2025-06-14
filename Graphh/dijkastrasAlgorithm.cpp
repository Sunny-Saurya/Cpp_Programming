#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    unordered_map<int, list<pair<int, int>>> adj;

    void addEdges(int u, int v, int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    void printList(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << "(" << j.first << ", " << j.second << ") ";
            }
            cout << endl;
        }
    }

    vector<int> dijkastra(int n, int e, int src){

        vector<int> dist(n+1, INT_MAX);

        set<pair<int, int>> st;

        dist[src] = 0;
        st.insert(make_pair(dist[src], src));


        while(!st.empty()){
            
            // fetching top from the set

            auto top = *(st.begin());

            int nodeDist = top.first;
            int node = top.second;

            // erasing it from set

            st.erase(st.begin());

            // travesing node neighbour

            for(auto i : adj[node]){
                if(nodeDist + i.second < dist[i.first]){

                    auto record = st.find(make_pair(dist[i.first], i.first));

                    // if found then erase

                    if(record != st.end()){
                        st.erase(record);
                    }

                    dist[i.first] = nodeDist + i.second;
                    st.insert(make_pair(dist[i.first], i.first));

                }
            }


        }

        return dist;


    }
};

int main(){

    Graph g;

    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    int src;
    cout << "Enter source node : ";
    cin >> src;


    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;

        g.addEdges(u, v, w);
    }
    cout << "The adjacency list is : \n";
    g.printList();

    cout << "The shortest dist is : " << endl;

    vector<int> res = g.dijkastra(n, e, src);

    for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
}

}