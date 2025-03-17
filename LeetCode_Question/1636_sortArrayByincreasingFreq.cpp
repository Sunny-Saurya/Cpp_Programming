#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int> &nums){
    unordered_map<int,int> mpp;

    for(int i : nums){
        mpp[i]++;
    }

    sort(nums.begin(), nums.end(), [&](int a, int b){
        if(mpp[a] ==  mpp[b]) return a > b;
        return mpp[a] < mpp[b];
    });
    return nums;
}

int main()
{
    int n ;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    frequencySort(nums);
    for(int i : nums){
        cout << i << " ";
    }
}