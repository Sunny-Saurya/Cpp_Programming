// #include<iostream>
// using namespace std;

// int swapAlter(int arr[] , int n)
// {
//     int start = 0;
//     int end = 1;
//     while(start <= end)
//     {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }

// }

// int printArray(int arr [], int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         cout<< arr[i] << " ";
//     }
//     cout<< endl;

// }
// int main()
// {
//     int n;
//     cout<<"Enter size of an array: "<< " ";
//     cin>>n;

//     int arr[100];
//     for(int i = 0; i < 100; i++)
//     {
//         cin >> arr[i];
//     }

//     swapAlter(arr, n);
//     printArray(arr , n);
// };


#include<iostream>
using namespace std;


void reverse_array (int arr[], int n)
{
    int start = 0;
    int end = 1;

    while(start <= start+1)
    {
        swap(arr[start], arr[end]);
        start++;
        end++;
    }
}

 int printArray(int arr [], int n)
 {
     for(int i = 0; i < n; i++)
     {
         cout<< arr[i] << " ";
     }
     cout<< endl;
 }

int main()
{
    int n;
    cin>>n;

    int arr[100];

    for(int i  = 0; i < n; i++)
    {
        cin>> arr[i];
    }

    reverse_array( arr , n);
    printArray(arr ,n);
}