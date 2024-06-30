#include <iostream>
using namespace std;

bool isPresent(int arr[][20], int target, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter number of rows : " << " ";
    cin >> n;

    int m;
    cout << "Enter number of columns : " << " ";
    cin >> m;

    int arr[n][20];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int target;
    cout << "Enter taret element : " << " ";
    cin >> target;

    if (isPresent(arr, target, n, m))
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Element Not Found" << endl;
    }
    return 0;
}