#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> convertToNumber(string s , vector<int> &arr)
    {
        for(auto i : s){
            if(isdigit(i)){
                arr.push_back(i - '0');
            }
            
        }
        return arr;
    }
public:
    int secondHighest(string s) {
        vector<int> arr;
        convertToNumber(s, arr);
        sort(arr.begin(), arr.end());
        
        // for removing duplicates in the vector arr
        auto last = unique(arr.begin(), arr.end());
        arr.erase(last, arr.end());

        if(arr.size() >= 2){
            return arr[arr.size() - 2];   
        }

        return -1;
    }
};