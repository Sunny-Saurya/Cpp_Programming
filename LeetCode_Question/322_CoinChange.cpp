#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &arr, int amount, vector<int> &dp)
{
    // base case
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;

    if(dp[amount] != -1) return dp[amount];

    int mini = INT_MAX;

    for(int i = 0; i < arr.size(); i++)
    {
        int ans = coinChange(arr, amount-arr[i], dp);
        if(ans != INT_MAX)
        {
            mini = min(mini, ans+1);
        }

    }
    dp[amount] = mini;
    return dp[amount];

}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    for(int i =0; i < n; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }
    int amount;
    cout << "Enter the amount to create: ";
    cin >> amount;

    // DP question
    // recurssion and memoization
    vector<int> dp(amount+1, -1);

    int result = coinChange(arr, amount, dp);
    if(result == INT_MAX) cout << "Not possible to create the amount";
    else cout << "Minimum number of coins required: " << result;
}