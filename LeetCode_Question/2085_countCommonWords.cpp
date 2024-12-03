#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
    
        unordered_map<string, int> mpp1, mpp2;

        for(int i = 0; i < words1.size(); i++)
        {
            mpp1[words1[i]]++;
        }
    
        for(int j = 0; j < words2.size(); j++)
        {
            mpp2[words2[j]]++;
        }

        int count = 0;
        
        for (const auto& [word, freq] : mpp1) {
            if (freq == 1 && mpp2[word] == 1) {
                count++;
            }
        }
    return count;
    }
};