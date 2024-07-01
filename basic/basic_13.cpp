/*#include<iostream>
using namespace std;

int main(){
    int mx = -19999999;
    int n;
    cout<<"Enter the size of an array";
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(int i = 0; i<n; i++)
    {
        mx = max(mx, arr[i]);
        cout<<mx<<endl;
    }
    return 0;
}*/

// SUM OF ALL SUBARRAYS.
//Ques 1. Given an array of size n. output sum of each subarray of the given array.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    int current = 0;

    for(int i = 0; i<n; i++)
    {
        current = 0;
        for(int j = i; j<n; j++)
        {
            current = arr[j];
            cout<<"hahaha ==> "<<current<<endl;
        }
    }
    return 0;
}