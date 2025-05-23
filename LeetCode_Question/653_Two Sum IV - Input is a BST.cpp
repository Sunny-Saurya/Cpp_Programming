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

    void inorder(TreeNode* root, vector<int>&ans)
    {
        if(root == NULL) return;
        inorder(root ->  left, ans);
        ans.push_back(root -> val);
        inorder(root -> right,ans);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> ans;
        inorder(root, ans);

        int i = 0;
        int j = ans.size() - 1;

        while(i < j)
        {
            int sum = ans[i] + ans[j];
            if(sum == k) return true;

            if(sum < k) i++;

            if(sum > k) j--;
        }

        return false;
    }
};