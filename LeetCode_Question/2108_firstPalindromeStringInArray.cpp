#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool palindrome(string s)
    {
        string rev = s;
        reverse(s.begin(), s.end());
        return s == rev;

    }
public:
    string firstPalindrome(vector<string>& words) {
        
        for(auto word : words){
            if(palindrome(word)){
                return word;
            }
        }
        return "";
    }
};