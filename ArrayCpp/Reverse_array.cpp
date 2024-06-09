// #include<iostream>
// using namespace std;

// int Reverse_array(int arr[], int size)
// {
//     for(int i = size; i >= 0; i--)
//     {
//         cout<< arr[i] << " ";
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Enter the size of an array: "<<" ";
//     cin>>n;

//     int arr[100];

//     for(int i = 0; i < n; i++)''

//     {
//         cin>>arr[i];
//     }
//     for(int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout<<endl;
    
//     Reverse_array(arr, n);
// }

#include<iostream>
using namespace std;

int reverse (int arr[], int n)
{
    int start_point = 0;
    int end_point = n-1;

    while(start_point <= end_point)
    {
        swap(arr[start_point],arr[end_point]);
        start_point++;
        end_point--;
    }
}

void printarray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter size; "<< " ";
    cin>>n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverse(arr, n);
    printarray(arr,n);
};