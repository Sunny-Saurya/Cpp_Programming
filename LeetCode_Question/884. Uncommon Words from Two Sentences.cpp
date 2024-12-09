#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream ss1(s1), ss2(s2);
        string word;

        vector<string> ans;
        unordered_map<string, int> mpp;

        while(ss1 >> word)
        {
            mpp[word]++;
        }

        while(ss2 >> word)
        {
            mpp[word]++;
        }

        for(auto i: mpp)
        {
            if(i.second == 1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};