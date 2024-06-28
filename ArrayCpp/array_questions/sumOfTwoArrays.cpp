#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> v) {
    int s = 0;
    int e = v.size() - 1;

    while (s < e) {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> sumOfArrays(vector<int> &arr, int n, vector<int> &arr1, int m) {
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;

    while (i >= 0 && j >= 0) {
        int val1 = arr[i];
        int val2 = arr1[j];
        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    // first case
    while (i >= 0) {
        int sum = arr[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    // second case
    while (j >= 0) {
        int sum = arr1[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // third case
    while (carry != 0) {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    return reverse(ans);
}

int main() {
    int n;
    cout << "Enter size of first array : ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cout << "Enter size of second array : ";
    cin >> m;

    vector<int> arr1(m);
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    vector<int> sum = sumOfArrays(arr, n, arr1, m);

    for (int i = 0; i < sum.size(); i++) {
        cout << sum[i] << " ";
    }

    return 0;
}