#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void performOperation(string s, int &ans)
    {
        if(s == "X++" || s == "++X"){
            ans++;
        }
        else{
            ans--;
        }
    }
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto i : operations)
        {
            performOperation(i, ans);
        }
        return ans;
    }
};