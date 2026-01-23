// 2772. Apply Operations to Make All Array Elements Equal to Zero
// You are given a 0-indexed integer array nums and a positive integer k.

// You can apply the following operation on the array any number of times:

// Choose any subarray of size k from the array and decrease all its elements by 1.
// Return true if you can make all the array elements equal to 0, or false otherwise.

// A subarray is a contiguous non-empty part of an array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>Diff(n+1, 0);
        int curr = 0;
        for(int i =0 ; i < n; i++){
            curr += Diff[i];
            if(curr > nums[i]) return false;
            int d = nums[i] - curr;
            if(d == 0) continue;
            if(i + k > n) return false;

            curr += d;
            Diff[i+k] -= d;

        }
        return true;
    }
};