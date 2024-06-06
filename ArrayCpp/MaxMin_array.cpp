#include<iostream>

using namespace std;

int MaxMin(int arr[] , int size)
{
    int max = INT_MIN;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;

    int arr[100];

    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    for(int i = 0; i < size; i++)
    {
        cout<< arr[i] << " ";
    }

    int result = MaxMin(arr, size);
    cout<<"Maximum number is : " << result;
}