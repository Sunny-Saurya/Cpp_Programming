#include<iostream>
using namespace std;

int  searchKey(int arr[], int n, int s, int e,int key)
{
    int mid = s  + (e - s)/2;
    if(s >  e)
    {
        return 0;
    }
    if(arr[mid] == key)
    {
        return 1;
    }
    if(key > arr[mid])
        return searchKey(arr, n, mid + 1, e , key);
    if(key < arr[mid])
        return searchKey(arr, n, s, mid - 1, key);
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

    int key;
    cout << "Enter key : " << " ";
    cin >> key;

    int s = 0; 
    int e = n-1;

    int isFound = searchKey(arr, n, s, e, key);

    if(isFound)
    {
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found " << endl;
    }
}