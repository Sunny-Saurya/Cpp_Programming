#include<iostream>
using namespace std;

bool isSorted(int *arr, int n)
{
    if(n == 0 || n == 1)
    {
        return true;
    }
    if(arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remainingPart = isSorted(arr + 1, n-1);
        return remainingPart;
    }
}   

int main()
{
    int n;
    cout << "Enter size : " << " ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result  = isSorted(arr, n);
    if(result)
    {
        cout << "Array is sorted "<< endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }
    

}