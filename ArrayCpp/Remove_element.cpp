/*
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]

*/

#include <iostream>
using namespace std;

int removeElement(int arr[], int n, int val)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != val)
        {
            cout << arr[i] << endl;
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the size of an array: " << " ";
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int val;
    cout << "Enter value : " << " ";
    cin >> val;

    removeElement(arr , n, val);
    // printArray( arr , n , val);

    
}