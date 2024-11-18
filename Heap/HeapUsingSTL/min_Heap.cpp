#include<bits/stdc++.h>
using namespace std;

void buildHeap(vector<int> &arr, int n)
{
    make_heap(arr.begin(), arr.end(), greater<int>());

}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildHeap(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}