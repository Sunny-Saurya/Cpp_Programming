#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>

class Solution {
  private:
  
  vector<int> nextSmallerElement(vector<int>&mat){
      
      int n = mat.size();
      
      stack<int> st;
      st.push(-1);
      
      vector<int> ans(n);
      
      for(int i = n-1; i >= 0; i--){
          
          int curr = mat[i];
          
          while(st.top() != -1 && mat[st.top()] >= curr){
              st.pop();
          }
          
          ans[i] = st.top();
          st.push(i);
      }
      return ans;
  }
  
   vector<int> prevSmallerElement(vector<int>&mat){
      
      int n = mat.size();
      
      stack<int> st;
      st.push(-1);
      
      vector<int> ans(n);
      
      for(int i = 0; i < n; i++){
          
          int curr = mat[i];
          
          while(st.top() != -1 && mat[st.top()] >= curr){
              st.pop();
          }
          
          ans[i] = st.top();
          st.push(i);
      }
      return ans;
  }
  
    int largestArea(vector<int>&mat){
        
        vector<int> next;
        next = nextSmallerElement(mat);
        
        vector<int> prev;
        prev = prevSmallerElement(mat);
        
        int area = INT_MIN;
        
        for(int i = 0; i < mat.size(); i++){
            
            int l = mat[i];
            
            if(next[i] == -1){
                next[i] = mat.size();
            }
            
            int b = next[i] - prev[i] - 1;
            
            int newArea = l*b;
            
            area = max(newArea, area);
        }
        return area;
        
    }
  public:
  
    int maxArea(vector<vector<int>> &mat) {
        // code here
        
        int area = largestArea(mat[0]);
        
        for(int i = 1; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                
                if(mat[i][j] != 0){
                    mat[i][j] = mat[i-1][j] + mat[i][j];
                }
                else{
                    mat[i][j] = 0;
                }
            }
            
            area = max(area, largestArea(mat[i]));
        }
        return area;
        
    }
};