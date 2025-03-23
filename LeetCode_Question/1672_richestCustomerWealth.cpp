#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        vector<int> arr;

        int row = accounts.size();
        int col = accounts[0].size();

        for (int i = 0; i < row; i++) {
            int sum = 0;
            for (int j = 0; j < col; j++) {
                sum += accounts[i][j];
            }
            arr.push_back(sum);
        }

        sort(arr.begin(), arr.end());
        return arr[arr.size() - 1];
    }
};