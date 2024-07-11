#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k)
{
    int mid = s + (e - s) / 2;

    if (s > e)
    {
        return false;
    }
    if (arr[mid] == k)
    {
        return true;
    }

    if (arr[mid] > k)
    {
        return binarySearch(arr, s, mid - 1, k);
    }

    if (arr[mid] < k)
    {
        return binarySearch(arr, mid + 1, e, k);
    }
}

int main()
{
    int n;
    cout << "Enter size : " << " ";
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter keys : " << " ";
    cin >> key;

    int s = 0;
    int e = n - 1;

    int ans = binarySearch(arr, s, e, key);
    cout << "ans : " << ans;
}