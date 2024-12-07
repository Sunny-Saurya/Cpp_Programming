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

    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root == NULL) return ;

        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);

    }

    TreeNode* solve(vector<int> v, int index)
    {
        if(index >= v.size()) return NULL;

        TreeNode* root = new TreeNode(v[index]);

        root -> right = solve(v, index + 1);

        return root;
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);

        return solve(v, 0);
    }
};