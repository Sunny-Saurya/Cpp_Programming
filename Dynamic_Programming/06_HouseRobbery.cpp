#include<bits/stdc++.h>
using namespace std;


class Solution {
    // Recursive
    int solve(vector<int>& nums, int index) {
        if (index == 0)
            return nums[0];
        if (index < 0)
            return 0;

        int pick = nums[index] + solve(nums, index - 2);
        int notPick = solve(nums, index - 1);

        return max(pick, notPick);
    }

    // Memoization
    int solveMemo(vector<int>& nums, int index, vector<int>& dp) {
        if (index == 0)
            return nums[0];
        if (index < 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int pick = nums[index] + solveMemo(nums, index - 2, dp);
        int notPick = solveMemo(nums, index - 1, dp);

        return dp[index] = max(pick, notPick);
    }

public:
    int rob(vector<int>& nums) {
        int index = nums.size();
        // return solve(nums,index-1);
        vector<int> dp(nums.size() + 1, -1);
        return solveMemo(nums, index - 1, dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed: " << sol.rob(nums) << endl;
    return 0;
}