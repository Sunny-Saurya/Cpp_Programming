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

        // Tabulation

    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];

            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }


public:
    int rob(vector<int>& nums) {
        int index = nums.size();
        // return solve(nums,index-1);
        vector<int> dp(nums.size() + 1, -1);
        return solveTab(nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed: " << sol.rob(nums) << endl;
    return 0;
}