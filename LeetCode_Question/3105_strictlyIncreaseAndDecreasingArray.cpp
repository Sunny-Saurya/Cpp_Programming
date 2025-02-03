#include<bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(int arr[], int n)
{
    int maxLen = 1;
    int increase = 1;
    int decrease = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i - 1]){
            decrease++, increase = 1;
        }
        else if( arr[i] < arr[i - 1]){
            decrease = 1, increase++;
        }
        else{
            decrease = 1, increase = 1;
        }

        maxLen = max(maxLen, max(increase, decrease));
    }

    return maxLen;
}

int main()
{
    int n;
    cout << " Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "The longest monotonic subarray length is: " << longestMonotonicSubarray(arr, n);
}