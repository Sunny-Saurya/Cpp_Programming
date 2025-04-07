#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;

        vector<int>ans;

        for(int i = 0; i < nums.size(); i++)
        {
            rightSum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            rightSum -= nums[i];
            ans.push_back(abs(leftSum - rightSum));

            leftSum += nums[i];
        }

        return ans;
    }
};