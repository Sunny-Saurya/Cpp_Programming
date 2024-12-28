#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isNumber(const string& word)
    {
        for(auto ch : word)
        {
            if(!isdigit(ch)){
                return false;
            }
        }
        return true;
    }
public:
    bool areNumbersAscending(string s) {

        vector<int> arr;
        string word;
        istringstream ss(s);

        while(ss >> word)
        {
            if(isNumber(word)){
                arr.push_back(stoi(word));
            }
        }

        for(int i = 1; i< arr.size(); i++)
        {
            if(arr[i-1] >= arr[i]){
                return false;
            }
        }
        return true;
    }
};