#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int n,int k,vector<int> Arr)
{
    // 1st Approach - Brute Force

    // sort(Arr.begin(), Arr.end());
    // return Arr[k-1];

    // 2nd Best appraoch - Using heap

    priority_queue<int>pq;
    // for first k element build max heap for that
    for(int i = 0; i < k; i++){
        pq.push(Arr[i]);
    }

    // for rest

    for(int i = k; i < n; i++){
        if(Arr[i] < pq.top()){
            pq.pop();
            pq.push(Arr[i]);
        }
    }

    // return the ans present on the top
    return pq.top();

}