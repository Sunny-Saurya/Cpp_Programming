// Structure of node
#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    private:
    
    int countNodes(Node* &tree){
        
        // base case
        
        if(tree == NULL) return 0;
        
        int ans = 1 + countNodes(tree -> left) + countNodes(tree -> right);
        
        return ans;
    }
    
    bool isCBT(Node* &tree, int index, int cnt){
        
        // base case;
        
        if(tree == NULL) return true;
        
        // iff index exceed
        
        if(index >= cnt){
            return false;
        }
        
        
        else{
            bool left = isCBT(tree, 2*index + 1, cnt);
            bool right = isCBT(tree, 2*index + 2, cnt);
            
            return (left && right);
        }
    }
    
    
    bool isMaxOrder(Node* &tree){
            
        // base case
        
        // leaf node
        
        if(tree -> left == NULL && tree -> right == NULL){
            return true;
        }
        
        if(tree -> right == NULL){
            return (tree -> data > tree -> left -> data);
        }
        
        else{
            bool left = isMaxOrder(tree -> left);
            bool right = isMaxOrder(tree -> right);
            
            return (left && right && (tree -> data > tree -> left -> data) && (tree -> data > tree -> right -> data));
        }
        
    }
    
    
  public:
    bool isHeap(Node* tree) {
        // code here
        int index = 0;
        int cnt = countNodes(tree);
        
        if(isCBT(tree, index, cnt) && isMaxOrder(tree)){
            return true;
        }
        else return false;
    }
};