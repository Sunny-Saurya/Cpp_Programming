#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
                ans.push_back(nums[i]);
            }
            else{
                nums[i] = 1;
                ans.push_back(nums[i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};