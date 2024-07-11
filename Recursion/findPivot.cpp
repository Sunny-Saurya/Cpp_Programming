#include <iostream>
using namespace std;

int getPivot(int pivot[], int n, int s, int e) {
    if (s > e) {
        return -1; // Base case: no pivot found
    }

    int mid = s + (e - s) / 2;

    // Check if mid is the pivot element
    if (mid < e && pivot[mid] > pivot[mid + 1]) {
        return mid + 1;
    }
    if (mid > s && pivot[mid] < pivot[mid - 1]) {
        return mid;
    }

    // Decide which half to search next
    if (pivot[mid] >= pivot[s]) {
        return getPivot(pivot, n, mid + 1, e);
    } else {
        return getPivot(pivot, n, s, mid - 1);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int pivot[100];

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> pivot[i];
    }

    int pivotIndex = getPivot(pivot, n, 0, n - 1);

    if (pivotIndex != -1) {
        cout << "The pivot element is: " << pivot[pivotIndex] << " at index " << pivotIndex << endl;
    } else {
        cout << "No pivot element found." << endl;
    }

    return 0;
}
