#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {

        bool a = false;

        if(isupper(word[0]))
        {
            if(word.length() > 1 && isupper(word[1]))
            {
                a = true;
            }
        }

        for(int i = 1; i < word.length(); i++)
        {
            if(a == true)
            {
                if(islower(word[i])) return false;
            }
            else{
                if(isupper(word[i])) return false;
            }
            
        }
        return true;
    }
};