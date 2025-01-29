#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

//     // 1st way -> using recursion 

// long long int solve(int n)
// {

//     // base case
//     // if(n == 1){
//     //     return 0;
//     // }

//     // if(n == 2){
//     //     return 1;
//     // }

//     // // recursion

//     // long long int ans =( ((n- 1) % MOD) * ((solve(n-2)% MOD) + (solve(n-1) % MOD )) % MOD); 
//     // return ans;
// }

// 2nd APPROACH - RECURSION + MEMOIZATION

// long long int solve(int n, vector<long long int> &dp)
// {
//     if(n == 1) return 0;
//     if(n == 2) return 1;

//     if(dp[n] != -1) return dp[n];

//     long long int dp[n] = ((n - 1LL) * ((solve(n - 2, dp) % MOD) + (solve(n - 1, dp) % MOD)) % MOD);
//     return dp[n];
// }




// 3rd appraoch with SC -> O(1)


// long long int solve(int n)
// {
//     long long int prev2 = 0;
//     long long int prev1 = 1;

//     for(int i = 3; i <= n; i++)
//     {
//         long long int first = prev2 % MOD;
//         long long int second = prev1 % MOD;
//         long long int sum = (first + second) % MOD;
//         long long ans = ((i - 1) * sum) % MOD;
//         prev2 = prev1;
//         prev1 = ans; 
//     }
//     return prev1;
// }


// 4TH  APPROACH  - TABULATION  

long long int solve(int n){
    vector<int> dp(n+1);

    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++)
    {
        long long int first = dp[i-1] % MOD;
        long long int second = dp[i-2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i-1) * sum) % MOD;

        dp[i] = ans;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    // Write your code here.
    // return solve(n);

    // vector<long long int> dp(n+1, -1);
    // return solve(n, dp);

    // return solve(n);

    return solve(n);
}