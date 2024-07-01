#include <iostream>
using namespace std;

void spiralArray(int arr[][20], int n, int m)
{
    int startrow = 0;
    int endingrow = n - 1;
    int startcol = 0;
    int endingcol = m - 1;

    while (startrow <= endingrow && startcol <= endingcol)
    {
        for (int i = startcol; i <= endingcol; i++)
        {
            cout << arr[startrow][i] << " ";
        }
        startrow++;

        for (int i = startrow; i <= endingrow; i++)
        {
            cout << arr[i][endingcol] << " ";
        }
        endingcol--;

        if (startrow <= endingrow)
        {
            for (int i = endingcol; i >= startcol; i--)
            {
                cout << arr[endingrow][i] << " ";
            }
            endingrow--;
        }

        if (startcol <= endingcol)
        {
            for (int i = endingrow; i >= startrow; i--)
            {
                cout << arr[i][startcol] << " ";
            }
            startcol++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter rows number : ";
    cin >> n;

    int m;
    cout << "Enter cols number : ";
    cin >> m;

    int arr[n][20];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The spiral array is : ";
    spiralArray(arr, n, m);

    return 0;
}