#include<iostream>
using namespace std;

int BinarySearch(int arr [], int n, int key)
{
    int start = 0;
    int end = n - 1;

    // IN this formula of mid there is a mynute mistake instead of this use (int mid  = start + (end - start) / 2 )
    int mid = ( start + end ) / 2;


    while( start <= end )
    {
        if( key == arr[mid] )
        {
            return mid;
        }
        if(key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = ( start + end ) / 2;   // mynute mistake instead of this use (int mid  = start + (end - start) / 2 )

    }
    return -1;
} 
int main()
{
    int n;
    cout<< "Enter the size of an array: "<< endl;
    cin>>n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The given Array is : "<< " ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int key;
    cout << "Enter any key that you want to seach : " << " ";
    cin >> key;

    int index = BinarySearch( arr , n , key);
    cout<<"The index of key " << key << " is : " << index << " ";

}