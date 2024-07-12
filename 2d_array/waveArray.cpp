#include<iostream>
using namespace std;

int waveArray(int arr[][20] , int n, int m)
{
     for(int j = 0; j < m; j++)
    {
        if(j & 1) // check odd, if odd then move from bottom to top
        {
            for(int i = 0; i < n; i++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        else{ // case for 0 and even. if even then move from top to bottom
            for(int i =  n - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
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
    
    waveArray(arr, n, m);
}