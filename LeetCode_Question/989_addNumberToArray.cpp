#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int number = 0;
        vector<int> result;

        for(int i =0 ; i < num.size(); i++)
        {
            number = number * 10 + num[i];
        }

        int ans = number + k;
        
        while(ans > 0)
        {
            result.push_back(ans % 10);
            ans = ans / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};