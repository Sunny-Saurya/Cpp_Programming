#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool check(vector<int>&nums, int k, int i){
        int n = nums.size();
        int count = 1;
        int x = nums[i];
        nums[i] = -1;
        i++;

        while(i < n && count < k){
            if(nums[i] == (x + 1)){
                count++;
                x++;
                nums[i] = -1;
            }
            i++;
        }
        if(count == k) return true;
        else return false;
    }
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(nums[i] != -1){
                if(check(nums, k, i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};