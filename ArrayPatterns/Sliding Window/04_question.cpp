// You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
// What is the longest sequence of successive songs where each song is unique?
// Input
// The first input line contains an integer n: the number of songs.
// The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
// Output
// Print the length of the longest sequence of unique songs.
// Example
// Input:

// 8
// 1 2 1 3 2 7 4 2

// Output:
// 5


#include<bits/stdc++.h>
using namespace std;

int longestSuccessiveSongs(vector<int>&arr){
    int n = arr.size();
    int maxLength = INT_MIN;

    int l = 0, r = 0;
    unordered_map<int,int>mpp;
    while(r < n){
        int num = arr[r];
        mpp[num]++;
        while(mpp[num] > 1){
            mpp[arr[l]]--;
            
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++;
        }
        maxLength = max(maxLength, r - l + 1);
        r++;
    }
    return maxLength;
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << longestSuccessiveSongs(arr)<< endl;

}