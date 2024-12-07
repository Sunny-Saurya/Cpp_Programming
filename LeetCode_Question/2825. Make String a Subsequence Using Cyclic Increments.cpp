#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;

        for (int i = 0; i < str1.size()  && j < str2.size(); i++) {
            if (str1[i] == str2[j] || (str1[i] + 1 - 'a') % 26 == (str2[j] - 'a'))
            {

                j++;
            }

        }
        return j == str2.size();
    }
};