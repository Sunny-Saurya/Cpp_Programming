// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    
    void heapify(vector<int>&arr, int size, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 *i + 2;
        
        if(left < size && arr[largest] < arr[left]){
            largest = left;
        }
        
        if(right < size && arr[largest] < arr[right]){
            largest = right;
        }
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, size, largest);
        }
    }
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        // 1 -based indexing
        
        vector<int>c;
        // c.push_back(-1);
        
        for(auto i : a){
            c.push_back(i);
        }
        
        for(auto i : b){
            c.push_back(i);
        }
        
        
        // BUILD HEAP
        int size = c.size();
        
        for(int i = (size/2)-1; i>=0; i--){
            heapify(c, size, i);
        }
        
        return c;
        
    }
};