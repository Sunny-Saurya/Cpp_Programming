#include<bits/stdc++.h>
using namespace std;

// Recursion
int fact(int n){
    if(n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

//Memoization

int factMemo(int n, vector<int>&dp){
    if(n == 0 || n == 1) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = n * fact(n-1);

    return dp[n];
}

int main(){
    int n = 7;
    vector<int>dp(n+1, -1);
    cout << "Factorial of " << n << ": " << factMemo(n, dp) << endl;
    // cout << "Factorial of " << n << ": " << fact(n) << endl;
}