#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans;
        int alice;
        int bob;

        sort(nums.begin(), nums.end());

        stack<int> st;

        for(int i = nums.size()- 1; i >= 0; i-- ){
            st.push(nums[i]);
        }

        while(!st.empty())
        {
            alice = st.top();
            st.pop();
            bob = st.top();
            st.pop();

            ans.push_back(bob);
            ans.push_back(alice);
        }

        return ans;
    }
};