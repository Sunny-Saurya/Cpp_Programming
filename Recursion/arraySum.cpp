#include<iostream>
using namespace std;

int arraySum(int *arr, int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return arr[0];
    }

    else{
        int remainingPart = arraySum(arr+1, n - 1);
        int sum = arr[0] + remainingPart;
        return sum;
    }
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

    int sum = arraySum(arr,n);
    cout << "Sum is " << sum << endl;

}