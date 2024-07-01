// 90 degree rotate array

// for this question we have to first do transpose of the matrix or array then further we can print it from last to fist

#include<iostream>
using namespace std;

int rotatedArray(int arr[][20] , int n, int m)
{
    cout << "Matrix after 90 deg rotation  : " << endl;
    for(int j = 0; j < m; j++)
    {
        for(int i = n-1 ; i >= 0; i--)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
    
int main()
{
    int n;
    cout << "Enter rows number : " << " ";
    cin >> n;
    
    int m;
    cout << "Enter cols number : " << " ";
    cin >> m;
    
    int arr[n][20];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cout << "The original array is : " << " ";
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    rotatedArray(arr,n,m);
}