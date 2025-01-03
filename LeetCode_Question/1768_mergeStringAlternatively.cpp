#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string result;
        int len1 = word1.size();
        int len2 = word2.size();

        int i = 0, j = 0;

        while(i < len1 && j < len2){
            result += word1[i++];
            result += word2[j++];
        }

        while(i < len1){
            result += word1[i++];
        }

        while(j < len2){
            result += word2[j++];
        }

        return result;
    }
};