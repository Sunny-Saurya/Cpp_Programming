#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        string word = "";
        for (int i = 0; i < s.length(); i++) {
           if (word.empty() || abs(word.back() - s[i]) != 32) {
                word += s[i];
            } else {
                word.pop_back();
            }
        }
    return word;
}
};
