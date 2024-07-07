#include<iostream>
using namespace std;

int main()
{

    // int n;
    // cout << "Enter  row and column size : " <<  " ";
    // cin >> n;

    int rows;
    cout << "Enter number of rows : " << ' ';
    cin >> rows;

    int cols;
    cout << "Enter number of cols : " << " ";
    cin >> cols;

    // int **arr = new int*[n];

    // when there are same number of rows...

    // for(int i = 0; i < n; i++)
    // {
    //     arr[i] = new int[n];
    // }

    // when the number of rows and cols are differerent

    int **arr = new int*[rows];

    for(int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }


    //taking input
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    //taking output

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing memory

    for(int i = 0; i < rows; i++)
    {
        delete [] arr[i];
    }

    delete []arr;
}