#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{

    if(size == 0 || size == 1)
    {
        return ;
    }
    for(int i = 0; i < size -1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, size-1);
}

int main()
{
    int n;
    cout << "Enter size of an array : "  << " ";
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}