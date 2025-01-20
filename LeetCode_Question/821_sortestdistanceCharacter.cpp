#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                ans.push_back(i);
            }
        }

        vector<int> v;
        for(int i = 0; i < s.size(); i++){
            int x = INT_MAX;
            for(int j = 0; j < ans.size(); j++){
                x = min(x, abs(i-ans[j]));
            }
            v.push_back(x);
        }
        return v;
    }
};