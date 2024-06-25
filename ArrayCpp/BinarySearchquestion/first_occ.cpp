// find out the first and last occurence of a element in a sorted array;

#include <iostream>
using namespace std;

int firstLastOcc(int arr[], int n, int key)
{
    // int first = -1, last = -1;
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e)
    {
        if(key == arr[mid])
        {
            ans = mid;
            e = mid -1;
        }
        else if(key > arr[mid])
        {
            s = mid + 1;
        }
        else if(key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of an array : " << " ";
    cin >> n;

    int arr[100];
    cout << "Enter the elements of an array : " << " ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the key element : " << " ";
    cin >> key;

    int firstOcc = firstLastOcc(arr , n ,key);
    cout << "The first occurence of the key element is : " << firstOcc << endl;
}