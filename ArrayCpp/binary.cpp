// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    
    while(s <= e){
        if(arr[mid] == key)
        {
            return mid;
        }
        if(key > arr[mid])
        {
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
    mid = s + (e-s)/2;
    }
    return -1;
}

int main() {
    // Write C++ code here
    int n;
    cout << "Enter the size of an array : " << " ";
    cin >> n;
    
    int arr[100];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int key;
    cout << "Enter value of Key : " << " ";
    cin >> key;
    
    int index = binarySearch(arr, n, key);
    cout << "index is  :  " << index << " ";

    
    return 0;
}