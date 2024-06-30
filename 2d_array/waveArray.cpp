// create of 2d array

#include<iostream>
using namespace std;


int waveArray(int arr[3][3], int n, int m)
{
    for(int j = 0; j < m; j++)
    {
        if(m & 1) // check odd, if odd then move from bottom to top
        {
            for(int i =  n - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        else{ // case for 0 and even. if even then move from top to bottom
            for(int i = 0; i < n; i++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int  main(){
    int arr[3][3]; // initialization of a 2d array

    // input 

    for(int i=0; i<3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    //output

    waveArray(arr,3,3);
}