#include <bits/stdc++.h> 
using namespace std;

// 1st APPROACH USING RECURSION :

// int solve(vector<int>&num , int x){
//     if(x == 0){
//         return  0;
//     }
//     if(x < 0){
//         return INT_MAX;
//     }

//     int mini = INT_MAX;

//     for(int i = 0; i < num.size(); i++){
//         int ans = solve(num,x - num[i]);

//         if(ans != INT_MAX){
//             mini = min(mini, 1+ans);
//         }
//     }
//     return mini;
// }
// int minimumElements(vector<int> &num, int x)
// {
//     // Write your code here.

//     int result = solve(num, x);
//     if(result == INT_MAX){
//         return -1;
//     }
//     return result;
// }

// 2ND APPROACH RECURSION + MEMOIZATION -> TOP DOWN APPROACH

// int solve(vector<int>&num, int x, vector<int> &dp){

//     if(x == 0){
//         return  0;
//     }
//     if(x < 0){
//         return INT_MAX;
//     }

//     if(dp[x] != -1) return dp[x];
    

    
//     int mini = INT_MAX;

//     for(int i = 0; i < num.size(); i++){
//         int ans = solve(num,x - num[i], dp);

//         if(ans != INT_MAX){
//             mini = min(mini, 1+ans);
//         }
//     }
//     dp[x] =  mini;
//     return mini;
// }   

// int minimumElements(vector<int> &num, int x)
// {
//     vector<int>dp(x+1, -1);
//     int ans = solve(num, x, dp);
//     if(ans == INT_MAX)return -1;
//     else return ans;


// }


// 3RD APPROACH TABULATION - BOTTOM UP APPROACH
int solve(vector<int>&num , int x){
    vector<int>dp(x+1, INT_MAX);

    dp[0] = 0;
    int mini = INT_MAX;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < num.size(); j++){
            if(i - num[j] >= 0 && dp[i-num[j]] != INT_MAX ){
                dp[i] = min(dp[i],1+ dp[i-num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX) return -1;

    return dp[x];
}

int minimumElements(vector<int>&num , int x){
    return solve(num, x);
}