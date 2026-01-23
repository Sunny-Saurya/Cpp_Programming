// Question 1: Given an array arr of length n and a variable k (k<=n). You need to find the maximum sum of any k length subarray with O(n) TC. [ai>=0]

#include<bits/stdc++.h>
using namespace std;

int maximumSum(vector<int>&arr, int k){
    int sum = 0;
    int l = 0, r = k;
    int maxi = 0;

    for(int i = 0; i < k; i++){
        sum += arr[i];
    }
    for(int i = k; i < arr.size(); i++){
        sum -= arr[l];
        l++;
        sum += arr[i];
        maxi = max(maxi, sum);
    }
    return maxi;
    
}

int main(){
    int n = 5;
    vector<int>arr = {1,3,2,4,5};
    int k = 4;

    cout << maximumSum(arr, k) << endl;


}