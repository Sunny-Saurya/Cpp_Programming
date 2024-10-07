#include<bits/stdc++.h>
using namespace std;
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    private:
    void inorder(TreeNode* root, vector<int> &arr)
    {
        if(root == NULL) return;

        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }

public:
    int getMinimumDifference(TreeNode* root) {

        vector<int>arr;

        if(root == NULL) return 0;

        inorder(root, arr);

        int diff = INT_MAX;

        for(int i = 1; i < arr.size(); i++)
        {
            diff = min(diff, arr[i] - arr[i-1]);
        }

        return diff;
    }
};