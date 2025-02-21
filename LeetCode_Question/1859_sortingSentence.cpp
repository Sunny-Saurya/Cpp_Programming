#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> str(10);
        istringstream ss(s);

        string word;
        int count = 0; // tracking the number of words

        while(ss >> word){
            int index = word.back() - '0'; // extracting the last char
            str[index] = word.substr(0, word.size() -1);
            count++;
        }

        string result;

        for(int i = 1; i <= count; i++){
            result += str[i] + " ";
        }
        
        result.pop_back();
        return result;


    }
};