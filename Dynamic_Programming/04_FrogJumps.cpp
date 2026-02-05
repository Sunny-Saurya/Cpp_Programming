#include <bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int> &arr, int index)
{
    if (index == 0)
        return 0;

    int left = minimumJumps(arr, index - 1) + abs(arr[index] - arr[index - 1]);

    int right = INT_MAX;
    if (index > 1)
        right = minimumJumps(arr, index - 2) + abs(arr[index] - arr[index - 2]);

    return min(left, right);
}

// Memoization

int minimumJumpsMemo(vector<int> &arr, int index, vector<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int left = minimumJumps(arr, index - 1) + abs(arr[index] - arr[index - 1]);

    int right = INT_MAX;
    if (index > 1)
        right = minimumJumps(arr, index - 2) + abs(arr[index] - arr[index - 2]);

    dp[index] = min(left, right);
    return dp[index];
}

// Tabulation

int minimumJumpsTab(vector<int> &arr, int index, vector<int> &dp)
{
    dp[0] = 0;

    for (int index = 1; index < arr.size(); index++)
    {
        int left = minimumJumps(arr, index - 1) + abs(arr[index] - arr[index - 1]);

        int right = INT_MAX;
        if (index > 1)
            right = minimumJumps(arr, index - 2) + abs(arr[index] - arr[index - 2]);

        dp[index] = min(left, right);
    }
    return dp[arr.size() -1];
}

int main()
{
    int n = 4;
    vector<int> arr = {20, 30, 40, 20};

    // cout << "The Minimum Energy Required to Jump is : "
    //      << minimumJumps(arr, n-1) << endl;
    vector<int> dp(n + 1, -1);
    cout << "The Minimum Energy Required to Jump is : "
         << minimumJumpsTab(arr, n - 1, dp) << endl;
}
