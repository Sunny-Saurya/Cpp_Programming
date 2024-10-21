#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertBST(Node* root, int value) {
    if (root == NULL) return new Node(value);
    
    if (root->data < value) {
        root->right = insertBST(root->right, value);
    } else {
        root->left = insertBST(root->left, value);
    }
    
    return root;
}

void inorder(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void preorder(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

void postorder(Node* root, vector<int>& ans) {
    if (root == NULL) return;
    ans.push_back(root->data);
    postorder(root->left, ans);
    postorder(root->right, ans);
}

int main() {
    Node* root = NULL;

    int n;
    while (true) {
        cin >> n;
        if (n != -1) {
            root = insertBST(root, n); // Fix: update root
        } else {
            break;
        }
    }

    vector<int> ans;
    // inorder(root, ans);
    // cout << "Inorder traversal : ";
    // for (int i : ans) {
    //     cout << i << " ";
    // }

    // postorder(root, ans);
    // cout << " postorder traversal : " ;
    // for (int i : ans) 
    // {
    //     cout << i << " ";
    // }
    preorder(root, ans);
    cout << "Preorder traversal : ";
    for(int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
