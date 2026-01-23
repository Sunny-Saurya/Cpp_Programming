// Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

#include<bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int>&arr, int k, int threshold){
    
        int count = 0;
        int sum = 0;
        int n = arr.size();
        int left = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int avg = sum / k;
        if (avg >= threshold)
            count++;

        for (int i = k; i < n; i++) {
            sum -= arr[left++];
            sum += arr[i];

            int avg = sum / k;
            if (avg >= threshold)
                count++;
        }
        return count;
}

int main(){
    vector<int>arr = {11,13,17,23,29,31,7,5,2,3};
    int k = 3;
    int threshold = 5;

    cout << numOfSubarrays(arr,k, threshold);
}