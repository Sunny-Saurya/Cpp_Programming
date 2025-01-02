#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < sentence.size(); i++)
        {
            mpp[sentence[i]]++;
        }

        for(char c = 'a'; c <= 'z'; c++)
        {
            if(mpp[c] == 0){
                return false;
            }
        }
        return true;
    }
};