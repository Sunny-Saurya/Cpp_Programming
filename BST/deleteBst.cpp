#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to find the minimum element in the right subtree
Node* minimumElement(Node* root) {
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// Insertion function for BST
Node* insertBST(Node* root, int n) {
    if (root == NULL) return new Node(n);

    if (root->data > n) {
        root->left = insertBST(root->left, n);
    } else {
        root->right = insertBST(root->right, n);
    }
    return root;
}

// Deletion function for BST
Node* deleteFromBST(Node* root, int val) {
    if (root == NULL) return root;

    if (root->data == val) {
        // Case 1: No children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child (left or right)
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Two children
        if (root->left != NULL && root->right != NULL) {
            // Get the minimum element from the right subtree
            Node* mini = minimumElement(root->right);
            root->data = mini->data;
            root->right = deleteFromBST(root->right, mini->data);
            return root;
        }

    } else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}


void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;


    int n;
    while (true) {
        cin >> n;
        if (n != -1) { 
            root = insertBST(root, n);
        } else break;
    }

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    // Deleting a value from the BST
    int deleteVal;
    cout << "Enter value to delete: ";
    cin >> deleteVal;
    root = deleteFromBST(root, deleteVal);

    // Inorder traversal after deletion
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
