#include<iostream>
using namespace std;

int UniqueArray (int arr [], int n)
{
    int flag = 1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] != arr[i+1])
        {
            cout<<"Unique element is/are : " << arr[i];
        }
        else continue;
    }

}
int  main()
{
    int n;
    cout<<"Enter size of an array: "<< " ";
    cin>>n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    UniqueArray( arr , n);
}
