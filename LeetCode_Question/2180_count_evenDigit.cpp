#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int digitSum(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit;
            n /= 10;

        }
        return sum;
    }
public:
    int countEven(int num) {
        int count = 0;
        for(int  i = 2; i <= num; i++){
            if(digitSum(i) % 2 == 0){
                count++;
            }
        }
        return count;
    }
};