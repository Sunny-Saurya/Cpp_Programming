#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        // split the sentence into words

        istringstream stream(sentence);
        
        string word;

        int index = 1; // 1- based index

        while(stream >> word)
        {
            if(word.find(searchWord) == 0)
            {
                return index;
            }
            index++;
        }

        return -1;
        
       
    }
};