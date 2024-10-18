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
    int sumLeaf(TreeNode* root)
    {
        int sum = 0;
        if(root == NULL) return 0;

        if(root -> left != NULL && root -> left -> left == NULL && root -> left -> right == NULL)
        {
            sum = sum + root -> left -> val;
        }

        sum = sum + sumLeaf(root -> left);
        sum = sum + sumLeaf(root -> right);

        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeaf(root);
    }
};