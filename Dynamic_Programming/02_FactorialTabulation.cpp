#include<bits/stdc++.h>
using namespace std;

int factTab(int n, vector<int>&dp){
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; i++){

        dp[i] = i * factTab(i-1, dp);
    }

    return dp[n];
}

int main(){
    int n = 7;
    vector<int>dp(n+1, -1);
    cout << "Factorial of " << n << ": " << factTab(n, dp) << endl;
    // cout << "Factorial of " << n << ": " << fact(n) << endl;
}