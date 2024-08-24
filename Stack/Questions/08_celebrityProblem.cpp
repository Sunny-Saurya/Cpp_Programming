#include <iostream>
#include <stack>
#include<vector>
using namespace std;

class Solution
{
private:
    bool knows(vector<vector<int>> &arr, int a, int b)
    {
        return arr[a][b] == 1;
    }

public:
    int isCelebrity(vector<vector<int>> &arr, int n)
    {

        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(arr, a, b))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int candidate = s.top();

        // Check if all elements in the candidate's row are 0
        for (int i = 0; i < n; ++i)
        {
            if (arr[candidate][i] == 1)
            {
                return -1; // Candidate knows someone, hence cannot be a celebrity
            }
        }

        // Check if all elements in the candidate's column are 1, except for the candidate's row
        for (int i = 0; i < n; ++i)
        {
            if (i != candidate && arr[i][candidate] == 0)
            {
                return -1; // Someone does not know the candidate, hence cannot be a celebrity
            }
        }

        return candidate;
    }

};

int main()
{
    int n;
    cout << "Enter size of  array: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    
    Solution obj;
    int celebrity = obj.isCelebrity(arr, n);

    if (celebrity == -1)
    {
        cout << "No celebrity found." << endl;
    }
    else
    {
        cout << "Celebrity ID is: " << celebrity << endl;
    }
}