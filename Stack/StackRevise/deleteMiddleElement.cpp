// #include <bits/stdc++.h> 

// // 1ST APPROACH USING ITERATION

// void solve(stack<int>&inputStack, int count , int size){

//    int mid = size/2;

//    stack <int> temp;

//    for(int i =0; i<mid; i++){
//       temp.push(inputStack.top());
//       inputStack.pop();
//    }

//    if(!inputStack.empty()){
//       inputStack.pop();
//    }

//    while(!temp.empty()){
//       inputStack.push(temp.top());
//       temp.pop();
//    }
   
// }

// // 2nd APPROACH USING RECURSION

// // void solve(stack<int>&inputStack, int count , int size){

// //    if(count == size / 2){
// //       inputStack.pop();
// //       return ;
// //    }

// //    int store = inputStack.top();
// //    inputStack.pop();

// //    solve(inputStack, count+1, size);

// //    inputStack.push(store);

// // }


// void deleteMiddle(stack<int>&inputStack, int N){
	
//    // Write your code here

//    int count = 0;
//    solve(inputStack, count, N);
   
// }




#include<bits/stdc++.h>
using namespace std;

 void deleteMid(vector<int>&arr, stack<int>&st, vector<int>&ans){
      int n = arr.size();
      int mid = n /2 ;

      for(int i = 0; i < n; i++){
         if(i == mid){
            continue;
         }
         st.push(arr[i]);
      }

      while(!st.empty()){
         int top = st.top();
         ans.push_back(top);
         st.pop();
      }
}

int main(){
   int n;
   cout << "Enter size of an array : " << endl;
   cin >> n;

   vector<int>arr(n);

   for(int i =0 ; i < n; i++){
      cin >> arr[i];
   }

   stack<int>st;

   vector<int>ans;
   deleteMid(arr, st, ans);

   reverse(ans.begin(), ans.end());
   for(auto i : ans){
      cout << i << " ";
   }
}