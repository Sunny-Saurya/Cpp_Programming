#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isNumber(const string &c)
    {
        for(auto ch : c)
        {
            if(!isdigit(ch)) return false;
        }
        return true;
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<string> arr;
        for(auto &i : nums)
        {
            if(isNumber(i)){
                arr.push_back((i));
            }
        }

        sort(arr.begin(), arr.end(), [](const string &a, const string &b)
        {
            if(a.size() == b.size()){
                return a < b;
            }
            
            return a.size() < b.size();
            
        });

        return arr[arr.size() - k ];
    }
};