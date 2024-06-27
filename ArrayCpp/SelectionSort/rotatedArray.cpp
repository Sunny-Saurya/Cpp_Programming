// Rotated Array with the position of k

#include<iostream>
using namespace std;

int rotatedArray(int arr[], int n, int k)
{
    for(int i = k ; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for(int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
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

    cout << "The array you entered is : " << " ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k;
    cout << "Enter the index you want to rotate the array from : " << " ";
    cin >> k;

    cout << "The array after rotation " << " ";
    rotatedArray(arr, n, k);

}