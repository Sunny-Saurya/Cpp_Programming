#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c); // Convert to lowercase to handle uppercase vowels
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string reverseVowels(string s) {

        int i = 0;
        int j = s.length() - 1;

        while (i < j) {

            while (i < j && !isVowel(s[i])) {
                i++;
            }
            while (i < j && !isVowel(s[j])) {
                j--;
            }

            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};