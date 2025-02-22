#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 1st approach

        // int sum = 0;

        // for (int i = 0; i < numbers.size(); i++) {
        //     for (int j = i + 1; j < numbers.size(); j++) {
        //         if (numbers[i] + numbers[j] == target) {
        //             return {i+1, j+1};
        //         }
        //     }
        // }
        // return {};

        // 2nd approach

        int left = 0;
        int right = numbers.size()-1;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left + 1, right + 1};
            }

            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return{};
    }
};