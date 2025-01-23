#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int fibonacci(int n, vector<int> &dp)
    {
        // base case

        if(n <= 1) return n;

        // step 3:  checking the condition

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] =  fibonacci(n-1,dp) + fibonacci(n-2, dp);
        return dp[n];
    }
public:
    int fib(int n) {

        // step 1
        if(n == 0) return 0;

        vector<int> dp(n+1, -1);

        return fibonacci(n, dp);
    }
};

// solving it using dp