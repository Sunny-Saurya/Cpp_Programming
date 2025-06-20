// #include<bits/stdc++.h>
// using namespace std;

//1ST APPROACH USING - RECURSION + MEMOIZATION = Top Down APPRAOCH

// class Solution {

//     private:

//     int solve(vector<int>& cost, int n, vector<int>& dp){

//         // base case 

//         if(n == 0){
//             return cost[0];
//         }
//         if(n == 1){
//             return cost[1];
//         }

//         // STEP 3

//         if(dp[n] != -1) return dp[n];


//         // STEP 2
//         dp[n] = cost[n] +  min(solve(cost, n-1, dp) , solve(cost, n-2, dp));
//         return dp[n];

//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();

//         // STEP 1
//         vector<int>dp(n+1, -1);
//         int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
//         return ans;
//     }
// };

// 2ND APPROACH - Bottom up APPROACH - TABLULATION 

// class Solution {

//     private:

//     int solve(vector<int>& cost, int n){


//         vector<int>dp(n+1);

//         dp[0] = cost[0];
//         dp[1] = cost[1];


//         for(int i = 2; i < n; i++){
//             dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
//         }
//         return min(dp[n-1], dp[n-2]);
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         return solve(cost, n);
//     }
// };


// 4th approach - SPACE OPTIMIZATION 

// class Solution {

//     private:

//     int solve(vector<int>& cost, int n){

//         int prev2 = cost[0];
//         int prev1 = cost[1];


//         for(int i = 2; i < n; i++){
//             int ans = cost[i] + min(prev1 , prev2);
//             prev2 = prev1;
//             prev1 = ans;

//         }
//         return min(prev1, prev2);
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         return solve(cost, n);
//     }
// };