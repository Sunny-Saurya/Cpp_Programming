#include<bits/stdc++.h>
using namespace std;

// Define a Node class to represent a node in the binary search tree
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


Node* searchKey(Node* root, int key)
{
    if(root == NULL) return NULL;

    if(root -> data == key) return root;

    if(root -> data > key){
        return searchKey(root -> left, key);
    }
    
    return searchKey(root -> right, key);
    
}

int main()
{
    
    Node*  root = new Node(4);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(6);
    
    Node* result = searchKey(root, 5);

    if (result != NULL) {
        cout << "Key Found: " << result->data << endl; 
    } else {
        cout << "Key Not Found" << endl; 
    }

    return 0;
}