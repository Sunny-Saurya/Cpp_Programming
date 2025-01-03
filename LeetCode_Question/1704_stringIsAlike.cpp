#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countVowel(string s) {
            int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                count++;
            }

        }
        return count;
    }

public:
    bool halvesAreAlike(string s) {

        string s1;
        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            s1 += s[i];
        }

        string s2;
        for (int i = len / 2; i < s.size(); i++) {
            s2 += s[i];
        }

        if (countVowel(s1) == countVowel(s2)) {
            return true;
        }

        return false;
    }
};