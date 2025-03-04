#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        char ch;

        for(int i =0; i < s.size(); i++){
            for(int j = 0; j < i; j++){
                if(s[j] == s[i]){
                    return s[i];
                }
            }
        }
        return ch;
    }
};