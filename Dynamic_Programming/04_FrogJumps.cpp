#include<bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int>& arr, int index){
    if(index == 0) return 0;

    int left = minimumJumps(arr, index-1) 
               + abs(arr[index] - arr[index-1]);

    int right = INT_MAX;
    if(index > 1)
        right = minimumJumps(arr, index-2) 
                + abs(arr[index] - arr[index-2]);

    return min(left, right);
}

int main(){
    int n = 4;
    vector<int> arr = {20, 30, 40, 20};

    cout << "The Minimum Energy Required to Jump is : "
         << minimumJumps(arr, n-1) << endl;
}
