// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> parent, rank;

    // Constructor
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
int main() {
    // Write C++ code here
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    
    // checking ifor 3 and 7
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same Component \n";
    }
    else{
        cout << "Diffrent Component\n";
    }
    
    ds.unionByRank(3,7);
    
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same Component \n";
    }
    else{
        cout << "Diffrent Component\n";
    }
    
    
    

    return 0;
}
