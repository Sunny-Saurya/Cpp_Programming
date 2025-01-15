#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int convertToNumber(string str)
    {
        string word = "";
         for(auto c : str)
         {
            word += to_string(c - 'a');
         }
         return stoi(word);
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int firstNum = convertToNumber(firstWord);
        int secondNum = convertToNumber(secondWord);
        int thirdNum = convertToNumber(targetWord);

        if(firstNum + secondNum != thirdNum){
            return false;
        }
        return true;
    }
};