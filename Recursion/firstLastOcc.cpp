#include <iostream>
using namespace std;

int firstOcc(int *arr, int n, int s, int e, int k)
{
    if(s > e)
    {
        return -1;
    }

    int mid = s + (e - s)/2;
    
    if(arr[mid] == k)
    {
        if(mid == 0 || arr[mid - 1] != k)
        {
            return mid;
        }
        else return firstOcc(arr,n,s,mid -1, k);

    }

    if(arr[mid] > k)
    {
        e = mid -1;
    }
    if(arr[mid] < k)
    {
        s = mid + 1;
    }
}


int lastOcc(int *arr, int n, int s, int e, int k)
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

        // check --- f mid is n-1 or the element after arr[mid] is not equal to k, then mid is the last occurrence.
        
        if(mid == n-1 || arr[mid+1] != k)
        {
            return mid; // last occ
        }
        else{
            return lastOcc(arr, n, mid + 1,e,k);
        }
    }

    else if (k > arr[mid])
        return lastOcc(arr, n, mid + 1, e, k);
    else
        return lastOcc(arr, n, s, mid - 1, k);
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

    cout << "First occurence is at index  : " << firstOcc(arr, n, s, e, key) << endl;
    cout << "Last occurence is at index  : " << lastOcc(arr, n, s, e, key) << " ";


}