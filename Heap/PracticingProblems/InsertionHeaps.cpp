#include <bits/stdc++.h>
using namespace std;

void insertElement(vector<int>& arr, int &n, int number) {

    arr.push_back(number);
    n++;

    int index = n - 1; 

    // heapify UP
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            index = parent;
        } else {
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter the length of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int number;
    cout << "Enter the key to insert: ";
    cin >> number;

    cout << "\nArray before inserting:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    insertElement(arr, n, number);

    cout << "\nArray after inserting & heapifying:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;
}
