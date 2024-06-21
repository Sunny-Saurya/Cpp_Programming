// Bubble sort

#include<iostream>
using namespace std;

void bubbleSortArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <  n -i; j++)
        {
            if(arr[j] > arr[j+ 1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{
    int n ;
    cout << "Enter the size of an array : ";
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

    bubbleSortArray(arr , n);

    cout << "The sorted array from bubble sort is : " << " ";

    for(int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
}