#include<bits/stdc++.h>
using namespace std;

vector<int> sumArray(vector<int> &arr, int n, int target){
    
    int left = 0;
    int right = n-1;

    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            return {left+1, right+1};
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return {};
}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cout << "Enter target Element: ";
    cin >> target;
    
    sort(arr.begin(), arr.end());

    vector<int> result = sumArray(arr, n, target);

    if (!result.empty()) {
        cout << "Indices: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}