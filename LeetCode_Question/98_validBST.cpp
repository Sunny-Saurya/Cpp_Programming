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

    // 1st approach using - range 

    private:
    bool isValid(TreeNode* root, long min, long max)
    {
        if(root == NULL) return true;
        
        if(root -> val > min && root -> val < max)
        {
            bool left = isValid(root -> left, min, root -> val);
            bool right = isValid(root -> right, root -> val, max);
            return left && right;
        }
        else
            return false;
    }

    public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);

    }

    // 2nd approach to solve this using extra space --> vector

//     private:
//     void inorder(TreeNode* root, vector<int>&ans)
//     {
//         if(root == NULL) return;

//         inorder(root -> left, ans);
//         ans.push_back(root -> val);
//         inorder(root -> right, ans);
//     }

//     bool isSorted(vector<int> ans)
//     {
//         for(int i = 1; i < ans.size(); i++)
//         {
//             if(ans[i] <= ans[i-1]) return false;
//         }
//         return true;
//     }


// public:
//     bool isValidBST(TreeNode* root) {
//         // return isValid(root, LONG_MIN, LONG_MAX);

//         vector<int> ans;
//         inorder(root, ans);
//         if(isSorted(ans)){
//             return true;
//         }
//         return false;
        
//     }
};