#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int solve(vector<vector<int>>&vis,vector<vector<int>>& grid, int delRow[], int delCol[], queue<pair<pair<int,int>,int>>&q){

        int n = grid.size();
        int m = grid[0].size();

        int maxTime = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second;

            maxTime = max(time,maxTime);

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 &&  newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !vis[newRow][newCol]){

                    q.push({{newRow, newCol},  time + 1});
                    vis[newRow][newCol] = 1;
                    grid[newRow][newCol] = 2;

                }
            }

        }

        for(int i = 0; i < n; i++){
            for(int j =  0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    return -1;
                }
            }
        }
        return maxTime;


    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>>q;

        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        return solve(vis, grid,delRow, delCol, q);
    }
};