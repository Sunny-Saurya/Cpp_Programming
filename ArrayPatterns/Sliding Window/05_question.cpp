// 209. Minimum Size Subarray Sum

#include<bits/stdc++.h>
using namespace std;

int minimumSubarray(vector<int>&arr, int target){
    int minLength = INT_MAX;
    int l = 0, r= 0;
    int n = arr.size();
    int sum = 0;
    int currLen = 0;

    while(r < n){
        sum += arr[r];
        r++;

        while(l < r && sum >= target){
            currLen = r - l;
            if(minLength > currLen){
                minLength = r -l;
            }
            sum -= arr[l++];
        }
    }
    if(minLength == INT_MAX) return 0;
    return minLength;
}

int main(){
    vector<int>arr = {2,3,1,2,4,3};
    int target = 7;

    cout << minimumSubarray(arr, target);
    return 0;

}