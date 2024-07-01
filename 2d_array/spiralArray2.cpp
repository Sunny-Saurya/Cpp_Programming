#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& arr, int n, int m)
{
    vector<int> ans;
    
    int row = arr.size();
    int col = arr[0].size();
    
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row -1 ;
    int endingCol = col-1;
    
    int count = 0;
    int total = row * col;
    
    while(count < total)
    {
        // first row
        
        for(int i = startingCol; count < total && i <= endingCol; i++)
        {
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;
        
        // last column
        
        for(int i = startingRow; count < total && i <= endingRow; i++)
        {
            ans.push_back(arr[i][endingCol]);
            count++;
        }
        endingCol--;
        
        // last row
        
        if(startingRow <= endingRow)
        {
            for(int i = endingCol; count < total && i >= startingCol; i--)
            {
                ans.push_back(arr[endingRow][i]);
                count++;
            }
            endingRow--;
        }
        
        // first column
        
        if(startingCol <= endingCol)
        {
            for(int i =  endingRow; count < total && i >= startingRow; i--)
            {
                ans.push_back(arr[i][startingCol]);
                count++;
            }
            startingCol++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter rows : " << " ";
    cin >> n;
    
    int m;
    cout << "Enter columns : " << " ";
    cin >> m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++ )
        {
            cin >> arr[i][j];
        }
    }
    
    cout << "The original array is : " << endl;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++ )
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<int> result = spiralMatrix(arr, n, m);
    
    cout << "The spiral order is : ";
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}