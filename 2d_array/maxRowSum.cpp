#include <iostream>
using namespace std;

void maximumRow(int arr[][20], int n, int m)
{
    int maxi = -123;

    int rowIndex = -1;
    
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = i;
        }
    }
    cout << "maximum is : " << maxi << endl;
    cout << "row index is : " << rowIndex << " ";
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

    maximumRow(arr, n, m);
    // cout << "Sum of all elements in the array is : " << maxi << endl;
}