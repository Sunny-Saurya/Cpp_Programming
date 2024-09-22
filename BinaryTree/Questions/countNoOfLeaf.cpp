#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    // constructor

    Node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1) return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

void inorderTraversal(Node* root, int &count)
{
    if(root == NULL) return;

    inorderTraversal(root -> left, count);
    // leaf node

    if(root -> left == NULL && root -> right == NULL)
    {
        count++;
    }

    inorderTraversal(root -> right, count);
}

int noOfLeafNode(Node* root)
{
    int count = 0;
    inorderTraversal(root, count);
    cout << count << " Leaf present in the tree";
}



int main()
{
    Node* root = NULL;
    buildTree(root);
}