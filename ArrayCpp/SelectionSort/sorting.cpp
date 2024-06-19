// selection sort

#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
    
}
int main()
{
    int n;
    cout << "Enter the size of an array : " << "  ";
    cin >> n;

    int arr[100];
    cout << "Enter the elements of an array : " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Entered elements of an array : " << " ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    
    selectionSort(arr, n);
    cout << endl;
    cout << "Sorted elements of an array : " << " ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}