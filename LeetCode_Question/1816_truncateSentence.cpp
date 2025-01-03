#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        
        istringstream ss(s);
        string word = "";
        vector<string> ans;

        while(ss >> word){
            ans.push_back(word);
        }

        string word1;
        for(int i =0; i < k; i++){
            word1+= ans[i];
            if(i < k-1){

            word1 += " ";
            }
        }
        return word1;
    }
};