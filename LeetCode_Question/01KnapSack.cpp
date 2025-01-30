#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // Base case
    if(index == 0){
        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    int include = 0;
    if(weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index], dp);

    int exclude = solve(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));  // Added missing semicolon
    return solve(weight, value, n - 1, maxWeight, dp);
}

int main() {
    vector<int> weight = {1, 2, 3, 5};
    vector<int> value = {40, 50, 100, 120};
    int maxWeight = 5;
    int n = weight.size();

    cout << "Maximum value in Knapsack: " << knapsack(weight, value, n, maxWeight) << endl;
    return 0;
}
