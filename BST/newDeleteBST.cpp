// You are using GCC
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left ;
    Node* right;
    
    Node(int data){
        this -> data = data;
        this -> left = left;
        this -> right = right;
    }
};

Node* insertBST(Node* root, int value)
{
    if(root == NULL) return new Node(value);
    
    if(root -> data > value){
        root -> left = insertBST(root -> left, value);
    }
    else{
        root -> right = insertBST(root -> right, value);
    }
    
    return root;
}

void inorder(Node* root)
{
    if(root == NULL) return;
    
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

Node* maximum(Node* root)
{
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val)
{
    if(root == NULL) return root;
    
    root->left = deleteFromBST(root->left, val);
    root -> right = deleteFromBST(root -> right, val);
      
    if(root -> data == val)
    {
        // 0 child
        
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }
        
        // 1 child
        
            if(root -> left != NULL && root -> right == NULL){
                Node* temp = root -> left;
                delete root;
                return temp;
            }
            
            if(root -> right != NULL && root -> left == NULL){
                Node* temp  = root -> right;
                delete root;
                return temp;
            }
            
        // 2 child
            
            if (root->left != NULL && root->right != NULL) {
            int mini = maximum(root->left) -> data;
            root->data = mini;
            root->left = deleteFromBST(root->left, mini); 
        }
    }
    return root;
}

int main()
{
    int value;
    Node* root = NULL;
    
    while(cin >> value)
    {
        if(value == -1) break;
        root = insertBST(root, value);
    }
    cout << "Original BST: ";
    inorder(root);
    cout << endl;
    
    deleteFromBST(root, 5);
    inorder(root);
    
    
    
}