#include<bits/stdc++.h>
using namespace std;

void buildHeap(vector<int> &arr, int n)
{
    make_heap(arr.begin(), arr.end());

}

void heapSort(vector<int> &arr)
{
    // priority_queue<int> sort_heap(arr.begin() , arr.end());
    // while(!sort_heap.empty()){
    //     cout<< sort_heap.top() << " ";
    //     sort_heap.pop();
    // }
    
    make_heap(arr.begin() , arr.end());
    sort(arr.begin() , arr.end());
    for(int i = 0 ; i < arr.size() ; i++){
        cout<< arr[i] << " ";
    }
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
    cout << endl;
    heapSort(arr);

    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}