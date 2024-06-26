// search the value in the sorted array

#include<iostream>
using namespace std;


int getPivot(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;

    while (s < e)
    {
        if(arr[mid] >= arr[0])
        {
            s  = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
    
}


int binarySearch(int arr[], int sp, int ep, int key)
{
    int s = sp;
    int e = ep;
    int mid = s + (e - s)/2;

    while (s <= e)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        if(key >= arr[mid]){
            s = mid + 1;
        }
        if(key <= arr[mid])
        {
            e = mid -1;
        }
        mid = s + (e - s)/2;
    }
    return -1;
    
}

int findPosition( int arr[], int n, int key)
{
    int pivot = getPivot(arr, n);
    if(key >= arr[pivot] && key <= arr[n-1])
    { // BS ON SECOND LINE
        return binarySearch(arr,pivot, n-1, key); // startpoint = pivot, ending point = n-1;
    }
    else{ // BS ON FIRST LINE
        return binarySearch(arr, 0, pivot-1, key);
    }
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

    cout << "The array you entered is : " << " ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int key;
    cout << "Enter key : " << " ";
    cin >> key;

    int isKey = findPosition(arr, n, key);
    cout << "Key is at index : " << isKey << " ";
}