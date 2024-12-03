#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int k = 0;
        string ans = "";

        for(int i = 0; i < s.length(); i++)
        {
            if(k < spaces.size() && i == spaces[k])
            {
                ans.push_back(' ');
                k++;
            }
            ans.push_back(s[i]);
        }
    return ans;
    }
};