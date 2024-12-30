#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        vector<char> prefix;
        bool found = false;


        for(auto i : word){
            prefix.push_back(i);
            if(i == ch){
                found = true;
                break;
            }
        }

        if(!found) return word;

        reverse(prefix.begin(), prefix.end());

        string result;
        for(auto i : prefix){
            result.push_back(i);
        }

        for(int i = prefix.size(); i < word.size(); i++){
            result.push_back(word[i]);
        }
        return result;
        


        // 2nd approach to solve this question 

        // int pos = word.find(ch);

        // if(pos < 0) return word;

        // reverse(word.begin(), word.begin() + pos + 1);
        // return word;
    }
};