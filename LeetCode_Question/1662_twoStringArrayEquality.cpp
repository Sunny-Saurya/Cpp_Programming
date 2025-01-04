#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1;
        for(auto i : word1){
            str1 += i;
        }

        string str2;
        for(auto i : word2){
            str2 += i;
        }

        if(str1 == str2){
            return true;
        }
        return false;
    }
};