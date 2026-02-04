#include<bits/stdc++.h>
using namespace std;

// Memoization

int climbingStair(int n, vector<int>&dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = climbingStair(n-1,dp) + climbingStair(n-2, dp);
    return dp[n];
}

// Tabulation


int climbingStairTab(int n, vector<int>&dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = climbingStair(i-1,dp) + climbingStair(i-2, dp);
    }
    return dp[n];
}

// space optimisation

int climbingStairSpace(int n, vector<int>&dp){
    int prev2 = 0;
    int prev1 = 1;

    for(int i = 2; i <= n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n = 5;
    vector<int>dp(n+1, -1);
    cout << "The Total number of Ways to reach " << n << " stairs is " << " : " << climbingStairSpace(n, dp) << endl;

}