#include<iostream>
using namespace std;

int rotateArray(int arr[], int n, int k)
{
    int ans[n];

    for(int i = 0; i < n; i++)
    {
        ans[(i+k) % n] = arr[i]; // formula to rotate array.
    }

    arr = ans;

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] <<  " ";
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

    int k;
    cout <<"Enter value from you want to rotate : " << " ";
    cin >> k;

    rotateArray(arr,n,k);

}