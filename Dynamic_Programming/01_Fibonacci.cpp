#include<bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int>&dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}

int main(){
    int n = 6;
    vector<int>dp(n+1, -1);
    cout << "Fibonacci of " << n << " : " << fibo(n, dp) << endl;
}