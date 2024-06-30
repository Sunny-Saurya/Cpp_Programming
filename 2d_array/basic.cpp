// create of 2d array

#include<iostream>
using namespace std;

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
    for(int i=0; i<3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";

        }
        cout << endl;
    }
}