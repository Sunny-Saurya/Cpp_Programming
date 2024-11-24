#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        unordered_map<int, int> mpp;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for(auto i : mpp)
        {
            if(i.second == 1)
            {
                sum += i.first;
            }
        }
    return sum;
    }

};