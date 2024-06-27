// CODE STUDIO QUESTION :  REVERSE THE ARRAY AFTER THE M POSITON 

#include<iostream>
using namespace std;


int reverseAtIndex(int arr[], int n, int m)
{
    int s = m+1;
    int e = n-1;

    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    
}


int main()
{
    int n;
    cout << "Enter the size :  " << " ";
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The given array is : " << " ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    int m;
    cout << "Enter the index at which you want to reverse : " << " ";
    cin >> m;

    cout << endl;

    cout << "The reverse array at given index is : " << " ";

    reverseAtIndex(arr, n, m);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}