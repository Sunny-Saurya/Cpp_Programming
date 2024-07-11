#include <iostream>
using namespace std;

int firstOcc(int *arr, int n, int s, int e, int k)
{
    // Base case

    if (s > e)
    {
        return -1;
    }

    // mid 

    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
    {

        // check --- f mid is 0 or the element before arr[mid] is not equal to k, then mid is the first occurrence.
        
        if(mid == 0 || arr[mid-1] != k)
        {
            return mid;
        }
        else{
            return firstOcc(arr, n, s,mid - 1,k);
        }
    }

    else if (k > arr[mid])
        return firstOcc(arr, n, mid + 1, e, k);
    else
        return firstOcc(arr, n, s, mid - 1, k);
}

int main()
{
    int n;
    cout << "Enter size : " << " ";
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: " << " ";
    cin >> key;

    int s = 0;
    int e = n - 1;

    cout << "First occurence is : " << firstOcc(arr, n, s, e, key) << " ";
}