//********************** sum of left child *****************************


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertBST(Node* root, int value)
{
    if(root == NULL) return new Node(value);
    if(root -> data > value)
    {
        root -> left = insertBST(root -> left, value);
    }
    else{
        root -> right = insertBST(root -> right , value);
    }
    
    return root;
}


// void inorder(Node* root)
// {
//     int sum = 0;
//     if(root == NULL ) return;
//     sum = sum + inorder(root -> left) + inorder(root -> right);
//     cout << sum << endl;
// }


int sumOfRightChild(Node* root)
{
    if(root == NULL) return 0;
    
    int sum = 0;
    
    if(root -> right != NULL) sum = sum + root -> right -> data;
    
    sum = sum + sumOfRightChild(root -> left);
    sum = sum + sumOfRightChild(root -> right);
    
    return sum;
}
// void preorder(Node* root)
// {
//     if(root == NULL) return;
//     cout << root -> data << " ";
//     preorder(root -> left);
//     preorder(root -> right);
// }

int main()
{
    int value;
    Node* root = NULL;
    
    while(cin >> value)
    {
        if(value == -1) break;
        root = insertBST(root, value);
    }
    
    // inorder(root);
    // preorder(root);

    cout << "sum of right children is " << sumOfRightChild(root);
}




















