#include<iostream>
using namespace std;

void merge(int *arr, int s , int e)
{
    int mid = s + (e - s) / 2;

    // Length of left part
    int len1 = mid - s + 1;

    // Length of right part
    int len2 = e - mid;

    // Create two arrays in which you copy the elements
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy left elements into the first array
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    // Copy right elements into the second array
    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge two sorted arrays---> first + second
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy remaining elements of first array if any
    while(index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    // Copy remaining elements of second array if any
    while(index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Free the memory allocated for the temporary arrays
    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e)
{
    // base condition
    
    if(s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // Sort the left part
    mergeSort(arr, s, mid);

    // Sort the right part
    mergeSort(arr, mid + 1, e);

    // Merge both parts
    merge(arr, s, e);
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
