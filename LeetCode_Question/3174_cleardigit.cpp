#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {

        string ans;

        for(char ch : s)
        {
            if(isdigit(ch))
            {
                if(!ans.empty())
                    ans.pop_back();
            }
            else
                ans.push_back(ch);
        }
        return ans;
    }
};
