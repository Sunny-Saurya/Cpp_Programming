#include<bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int>&dp){
    dp[0] = 0, dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = fibo(i-1, dp) + fibo(i-2, dp);
    }
    return dp[n];
}

int main(){
    int n = 6;
    vector<int>dp(n+1, -1);
    cout << "Fibonacci of " << n << " : " << fibo(n, dp) << endl;
}