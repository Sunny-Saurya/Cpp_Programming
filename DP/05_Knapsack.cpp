#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    
    int solve(int capacity, int index, vector<int> &val, vector<int> &wt){
        
        // base case
        // suppose there is only one items
        
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        int include = 0;
        
        if(wt[index] <= capacity){
            include = val[index] + solve(capacity - wt[index], index -1, val, wt);
        }
        
        int exclude = 0 + solve(capacity, index-1, val,  wt);
        
        int ans = max(exclude, include);
        return ans;
    }
    
    
    int solveMem(int capacity, int index, vector<int> &val, vector<int> &wt, vector<vector<int> > &dp){
        
        // base case
        // suppose there is only one items
        
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        if(dp[index][capacity] != -1){
            return dp[index][capacity];
        }
        
        int include = 0;
        
        if(wt[index] <= capacity){
            include = val[index] + solveMem(capacity - wt[index], index -1, val, wt, dp);
        }
        
        int exclude = 0 + solveMem(capacity, index-1, val,  wt, dp);
        
        dp[index][capacity] = max(exclude, include);
        return dp[index][capacity];
    }
    
    
    int solveTab(int capacity, vector<int> &val, vector<int> &wt, int n){
        
        // initializing  dp matrix
        
        vector<vector<int> > dp(n, vector<int>(capacity+1, 0));
        
        // base case
        
        for (int i = wt[0]; i <= capacity; i++) {
        dp[0][i] = val[0]; // if the item can fit, take it
    }

        
        // for the remaining cases
        
        for(int index = 1; index < n; index++){
            for(int w = 0; w <= capacity; w++){
                
                int include = 0;
        
                if(wt[index] <= w){
                    include = val[index] + dp[index -1][w - wt[index]];
                }
                
                int exclude = 0 + dp[index-1][w];
                
                dp[index][w] = max(exclude, include);
                
            }   
        }
        return dp[n-1][capacity];
        

    }
    
    int solveSpace(int capacity, vector<int> &val, vector<int> &wt, int n){
        
        // initializing  dp matrix
        
        vector<int>prev(capacity+1, 0);
        vector<int>curr(capacity+1, 0);
        
        // base case
        
        for (int i = wt[0]; i <= capacity; i++) {
            prev[i] = val[0]; // if the item can fit, take it
        }

        
        // for the remaining cases
        
        for(int index = 1; index < n; index++){
            for(int w = 0; w <= capacity; w++){
                
                int include = 0;
        
                if(wt[index] <= w){
                    include = val[index] + prev[w - wt[index]];
                }
                
                int exclude = 0 + prev[w];
                
            curr[w] = max(exclude, include);
                
            }   
            
            prev = curr;
        }
        return prev[capacity];
        

    }
    
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = val.size();
        // return solve(W,n-1, val, wt);
        
        // vector<vector<int> > dp(n, vector<int>(W+1, -1));
        // return solveMem(W,n-1, val, wt, dp);
        
        // return solveTab(W, val, wt, n);
        
        return solveSpace(W, val, wt, n);
        
    }
};