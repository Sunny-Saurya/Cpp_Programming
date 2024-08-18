#include <iostream>
#include <vector> // Include the vector library
using namespace std;

vector<int> intersectionArray(vector<int> &arr, vector<int> &brr) {
    vector<int> ans; // Initialize ans vector

    int i = 0;
    int j = 0;

    while (i < arr.size() && j < brr.size()) {
        if (arr[i] == brr[j]) {
            // Checking to avoid duplicates
            if (ans.empty() || ans.back() != arr[i]) {
                ans.push_back(arr[i]);
            }
            i++;
            j++;
        } else if (arr[i] < brr[j]) { // Fixed the parentheses
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> arr(n); // Initialize vector with size n
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> brr(m); // Initialize vector with size m
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
    }

    vector<int> head = intersectionArray(arr, brr); // Corrected the type to vector<int>

    cout << "Intersection: ";
    for (int i = 0; i < head.size(); i++) {
        cout << head[i] << " ";
    }
    cout << endl;

    return 0;
}
