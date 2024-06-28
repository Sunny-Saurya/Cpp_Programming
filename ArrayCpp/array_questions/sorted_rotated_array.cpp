#include<iostream>
using namespace std;

bool sortedRotated(int arr[], int n)
{
    int count = 0;

    for(int i = 1; i  < n; i++)
    {
        if(arr[i-1] > arr[i])
        {
            count++;
        }
    }

    if(arr[n-1] > arr[0])
    {
        count++;
    }
    return count <=1;
}

int main()
{
    int n;
    cout << "Enter size : " << " ";
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sortedRotated(arr, n);
    
}