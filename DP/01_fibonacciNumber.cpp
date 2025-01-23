#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int> &dp)
{
    // base case
    if(n <= 1){
        return n;
    }

    // step 3: checking if the value is already computed
    if(dp[n] != -1){
        return dp[n];
    }

    // step 2 : storing the result in dp array
    dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    return dp[n];
};

int main()
{
    int n;
    cout << " Enter the number : ";
    cin >> n;

    // step 1.
    vector<int> dp(n+1, -1); // for storing the results of subproblems
    cout << "Fibonacci number at position " << n << " is " << fibonacci(n , dp);

}