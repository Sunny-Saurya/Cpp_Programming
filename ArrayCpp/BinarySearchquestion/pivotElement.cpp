// find the pivot element

#include<iostream>
using namespace std;

int pivotElement(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;
    
    while(s < e)
    {
        if(arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid  = s + (e - s)/2;
    }
    return s;
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
    
    cout << "The  Element you entered : " << endl;
    
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int pivot = pivotElement(arr, n);
    cout << "The index of pivot element is : " << pivot << endl;
    cout << "The pivot element is : " << arr[pivot];
}