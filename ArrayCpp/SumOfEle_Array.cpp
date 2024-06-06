#include<iostream>
using namespace std;

int SumOfElement(int arr[] , int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int main()
{
    int size;
    cout<<"Enter the size of an array: "<<" ";
    cin>>size;

    int arr[100];

    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }


    for(int i = 0; i < size; i++)
    {
        cout<< arr[i] << " ";
    }

    cout<<endl;
    int result = SumOfElement(arr, size);
    cout<<"The sum of all element in the array is : "<< result << " ";
}