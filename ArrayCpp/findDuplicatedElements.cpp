#include<iostream>
using namespace std;

int checkDuplicate(int arr[], int n)
{
    int slow = arr[0];
    int fast = arr[arr[0]];

    // First phase: Detect if a cycle exists
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }

    // Second phase: Find the starting point of the cycle
    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main()
{
    int n;
    cout << "Enter Size: ";
    cin >> n;

    int arr[100];  

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Entered Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The duplicate element is: " << checkDuplicate(arr, n) << endl;

    return 0;
}
