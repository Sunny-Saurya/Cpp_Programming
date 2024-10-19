#include<iostream>
using namespace std;

class Node
{
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

Node* insertBST(Node* root, int n)
{
    if(root == NULL) return new Node(n);

    if(root -> data > n)
    {
        root -> left = insertBST(root -> left , n);
    }
    else{
        root -> right = insertBST(root -> right , n);
    }

    return root;
}

void postOrder(Node* root)
{
    if(root == NULL) return ;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

Node* searchBST(Node* root, int key)
{
    if(root == NULL) return NULL;

    if(root -> data == key) return root;

    if(key < root -> data)
    {
        return searchBST(root -> left , key);
    }
    else{
        return searchBST(root -> right , key);
    }
    
}

int main()
{
    Node* root = NULL;
    int n;

    while(cin >> n && n != -1)
    {
        root = insertBST(root, n);
    }

    postOrder(root);
    cout << endl;

    if(searchBST(root, 4) == NULL){
        cout << "Element not found";
    }
    else{
        cout << "Element found";
    }
    cout << endl;

    return 0;
}