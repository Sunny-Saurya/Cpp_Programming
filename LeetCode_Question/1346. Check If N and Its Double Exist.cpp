#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool a = false;
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = arr.size() -1 ; j >= 0; j--)
            {
                if(arr[i] == arr[j] *2 && i != j)
                {
                    a = true;
                }
            }
        }
        if(a) return true;
        else return false;
        
    }
};