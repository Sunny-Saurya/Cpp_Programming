#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    // constructor

    Node(int data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int n)
{
    if(root == NULL) return new Node(n);

    if(n > root -> data ){
        root -> right = insertBST(root -> right, n);
    }
    else{
        root -> left = insertBST(root -> left, n);
    }

    return root;
}

void inorderTraversal(Node* root)
{
    if(root == NULL) return ;

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

int main()
{
    Node* root = NULL;
    int n;
    
    while( cin >> n && n  != -1)
    {
        root =  insertBST(root, n);
    }
    inorderTraversal(root);
    cout << endl;
    return 0;
}