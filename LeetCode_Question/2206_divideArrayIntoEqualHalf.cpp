#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int count =  0;
        int key = nums.size() / 2;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]){
                count++;
                i++;
            }
        }
        if(count == key){
            return true;
        }
        return false;
    }
};