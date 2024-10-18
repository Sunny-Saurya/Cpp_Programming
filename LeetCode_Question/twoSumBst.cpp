#include <bits/stdc++.h> 

class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};


void inorder(BinaryTreeNode<int>* root, vector<int> &ans)
{
    if(root == NULL) return;

    inorder(root-> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> ans;
    inorder(root, ans);

    int sum = 0;
    int j = ans.size() -1;
    int i = 0;
    while(i < j){
        sum = ans[i] + ans[j];

        if(sum == target) return true;
        else if(sum > target) j--;
        else i++;
    }
    return false;

}

