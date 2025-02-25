#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int ans;
        while(b != 0){
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};