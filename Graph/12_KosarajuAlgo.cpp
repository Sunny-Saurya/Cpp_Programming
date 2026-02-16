#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
void addEdge(int u, int v){
    adj[u].push_back(v);
}

void dfs1(int node, stack<int>&s, vector<int>&vis){
    vis[node] = 1;

    for(auto &nei : adj[node]){
        if(!vis[nei]){
            dfs1(nei, s, vis);
        }
    }
    s.push(node);
}

void dfs2(int node, vector<int>trans[], vector<int>&vis){
    vis[node] = 1;
    for(auto &it : trans[node]){
        if(!vis[it]){
            dfs2(it, trans, vis);
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
 adj.resize(n);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;

        addEdge(u, v);
    }

    // step1 -> do dfs and  push it into stack

    stack<int>st;
    vector<int>vis(n,0);
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs1(i, st, vis);
    }

    // step2 -> change the arrow
    vector<int> transpose[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(auto it : adj[i]){
                transpose[it].push_back(i);
            }
        }

    // step3 -> dfs + go witht he order of stack
    int count = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(!vis[node]){
                count++;
                dfs2(node, transpose, vis);
            }
        }

    cout << "The SCCs of this Graph is : " <<  count << endl;
}