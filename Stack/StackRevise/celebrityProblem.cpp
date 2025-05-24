#include<bits/stdc++.h>
class Solution {
  private:
    
    bool knows(vector<vector<int> >& mat, int a, int b){
        return mat[a][b] == 1;
    }
  
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        
        for(int i = 0; i < mat.size(); i++){
            st.push(i);
        }
        
        // now take 2 and compare that
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(knows(mat,a, b)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        // Check if potentialCandidate is actually a celebrity
        if(st.empty()) return -1;
        
        int potentialCandidate = st.top();
        
        int zeroCount = 0;
        
        for(int i = 0; i < mat.size(); i++){
            if(i != potentialCandidate && mat[potentialCandidate][i] == 0){
                zeroCount++;
            }
        }
        
        if(zeroCount != mat.size()-1){
            return -1;
        }
        
        int oneCount = 0;
        
        for(int i = 0; i < mat.size(); i++){
            if(i != potentialCandidate && mat[i][potentialCandidate] == 1){
                oneCount++;
            }
        }
        
        if(oneCount != mat.size()-1){
            return -1;
        }
        
        return potentialCandidate;
        
        
    }
};