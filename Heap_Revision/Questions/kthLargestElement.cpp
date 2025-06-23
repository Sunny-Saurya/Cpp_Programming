#include <bits/stdc++.h> 
using namespace std;

 int findKthLargest(vector<int>& nums, int k) {

  // Write your code here

  // 1st - BRute Force



  // sort(nums.begin(), nums.end());

  // for(int i = 1; i < nums.size(); i++){
  //   if(nums[i-1] == nums[i]){
  //     continue;
  //   }
  //   return nums[nums.size() - k];
  // }
  
  
  // 2nd - best approach using HEAP

  priority_queue<int, vector<int>, greater<int>> pq;

  for(int i = 0 ; i < k; i++){
    pq.push(nums[i]);
  }

  // for rest

  int n = nums.size();

  for(int i = k; i < n; i++){
    if(nums[i] > pq.top()){
      pq.pop();
      pq.push(nums[i]);
    }
  }

  // return the top element
  return pq.top();

}