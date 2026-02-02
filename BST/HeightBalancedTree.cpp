#include<bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    private:
    
    Node* buildBST(vector<int>&arr, int l, int r){
        if (l > r) return nullptr;

        int mid = (l + r) / 2;
        Node* root = new Node(arr[mid]);

        root->left = buildBST(arr, l, mid - 1);
        root->right = buildBST(arr, mid + 1, r);

        return root;
    }
    
  public:
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
       return buildBST(arr, 0, arr.size() -1);
    }
};