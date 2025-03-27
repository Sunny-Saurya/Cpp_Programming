#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:

    string reverse(string s){
        string test;
        for(int i = s.size() - 1; i >= 0; i--){
            test += s[i];
        }
        return test;
    }
public:
    string reverseWords(string s) {
        string ans;
        string word;
        istringstream ss(s);


        while(ss >> word){
            string xyz = reverse(word);
            if(!ans.empty()) ans += " ";
            ans += xyz;
        }
        return ans;
    }
};