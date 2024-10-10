#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

// Updated function to return Node*
Node* insertIntoBST(Node* root, int d)
{
    // base case
    if(root == nullptr){
        return new Node(d);
    }

    if(d > root -> data){
        // go to right part
        root -> right = insertIntoBST(root -> right, d);
    }
    else{
        // go to the left part
        root -> left = insertIntoBST(root -> left, d);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);  // updating the root with the returned value
        cin >> data;
    }
}

// printing the element by using level order traversal

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            // End of the current level
            cout << endl;
            if(!q.empty()) { 
                // If there are more levels to process
                q.push(NULL);
            }  
        }
        else {
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}



int main()
{
    Node* root = nullptr;
    cout << "Enter data to create BST (enter -1 to stop): " << endl;

    takeInput(root);
    cout << "Printing the BST: " << endl;
    
    levelOrderTraversal(root);

    return 0;
}
