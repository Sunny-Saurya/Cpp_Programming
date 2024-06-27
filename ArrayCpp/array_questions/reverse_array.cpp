// #include<iostream>
// using namespace std;

// int reverseArray(int arr[], int n)
// {
//      for(int i = n-1; i >=0; i--)
//     {
//         cout << arr[i] << " ";
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter size: " << " ";
//     cin >> n;

//     int arr[100];
//     for(int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     reverseArray(arr,n);
   
// }

// using BINARY SEARCH

#include<iostream>
using namespace std;


int reverseArray(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e - s) /2;

    int i = 0;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    
}

int main()
{
    int n;
    cout<<"Enter size : "<< " ";
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "The array you given is : " << " ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "The reversed array is : " << " ";

    reverseArray(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}