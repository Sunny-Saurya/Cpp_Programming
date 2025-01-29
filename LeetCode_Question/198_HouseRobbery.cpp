#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int solve(vector<int> arr) {

    //     if (arr.size() == 0)
    //         return 0;
    //     if (arr.size() == 1)
    //         return arr[0];

    //     int prev2 = 0;
    //     int prev1 = arr[0];
    //     int ans;

    //     for (int i = 1; i < arr.size(); i++) {
    //         int incl = prev2 + arr[i];
    //         int excl = prev1;

    //         ans = max(incl, excl);
    //         prev2 = prev1;
    //         prev1 = ans;
    //     }
    //     return prev1;
    // }

public:
    int rob(vector<int>& nums) {

        // 1st approach

        // int n = nums.size();

        // if (n == 0)
        //     return 0;

        // if (n == 1)
        //     return nums[0];

        // vector<int> first(nums.begin(), nums.end() - 1); 
        // vector<int> second(nums.begin() + 1, nums.end());

        // return max(solve(first), solve(second));

        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 1; i <nums.size(); i++){
            int ans = max(prev1+ 0, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};
