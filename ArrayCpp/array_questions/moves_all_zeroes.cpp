#include<iostream>
using namespace std;


int moveZeroes(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int  j = i+1; j < n; j++)
        {
            if(arr[i] == 0)
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter size : " << " ";
    cin >> n;

    int arr[100];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    moveZeroes(arr,n);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}