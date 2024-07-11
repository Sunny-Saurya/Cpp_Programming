#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n, int k)
{
    // base case

    if(n == 0)
    {
        return false;
    }
    if(arr[0] == k)
    {
        return true;
    }
    else{
        int remainingParts = linearSearch(arr + 1, n - 1, k);
        return remainingParts;
    }
}

int main()
{
    int n;
    cout << "Enter size : " << " ";
    cin >> n;

    int arr[100];

    for(int i =0 ; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key : " << " ";
    cin >> key;

    int ans =  linearSearch(arr, n, key);
    if(ans)
    {
        cout << "FOUND" << endl;
    }
    else{
        cout << "NOT FOUND" << endl;
    }

}