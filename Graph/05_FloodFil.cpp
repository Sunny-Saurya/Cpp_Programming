#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(vector<vector<int>> &mirrorImage, vector<vector<int>> &vis, queue<pair<int, int>> &q, int delRow[], int delCol[], int newColor, int currColor)
    {

        int n = mirrorImage.size();
        int m = mirrorImage[0].size();
        // vector<int>ans;

        while (!q.empty())
        {

            auto it = q.front();
            // ans.push_back(it);
            q.pop();
            int r = it.first;
            int c = it.second;

            for (int i = 0; i < 4; i++)
            {
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && mirrorImage[newRow][newCol] == currColor && !vis[newRow][newCol])
                {

                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                    mirrorImage[newRow][newCol] = newColor;
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> mirrorImage = image;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int currColor = image[sr][sc];
        if (currColor == color)
            return image;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        q.push({sr, sc});
        vis[sr][sc] = 1;
        mirrorImage[sr][sc] = color;

        solve(mirrorImage, vis, q, delRow, delCol, color, currColor);
        return mirrorImage;
    }
};