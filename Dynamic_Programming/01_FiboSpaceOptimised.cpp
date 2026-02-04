#include<bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int>&dp){
    
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
    int n = 6;
    vector<int>dp(n+1, -1);
    cout << "Fibonacci of " << n << " : " << fibo(n, dp) << endl;
}