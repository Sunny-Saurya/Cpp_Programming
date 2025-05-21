#include <bits/stdc++.h> 

// 1ST APPROACH USING ITERATION

void solve(stack<int>&inputStack, int count , int size){

   int mid = size/2;

   stack <int> temp;

   for(int i =0; i<mid; i++){
      temp.push(inputStack.top());
      inputStack.pop();
   }

   if(!inputStack.empty()){
      inputStack.pop();
   }

   while(!temp.empty()){
      inputStack.push(temp.top());
      temp.pop();
   }
   
}

// 2nd APPROACH USING RECURSION

// void solve(stack<int>&inputStack, int count , int size){

//    if(count == size / 2){
//       inputStack.pop();
//       return ;
//    }

//    int store = inputStack.top();
//    inputStack.pop();

//    solve(inputStack, count+1, size);

//    inputStack.push(store);

// }


void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here

   int count = 0;
   solve(inputStack, count, N);
   
}

