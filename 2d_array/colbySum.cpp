#include <iostream>
using namespace std;

int rowWiseSum(int arr[][20], int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i][j];
        }
        cout << "sum is : " << sum << endl;
    }
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    rowWiseSum(arr, n, m);
    // cout << "Sum of all elements in the array is : " << sum1 << endl;
}