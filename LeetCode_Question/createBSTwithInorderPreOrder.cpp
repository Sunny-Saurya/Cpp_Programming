#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

class Solution {
private:
    int findPosition(int in[], int element, int n) {
        for (int i = 0; i < n; i++) {
            if (element == in[i]) {
                return i;
            }
        }
        return -1; // Return -1 if the element is not found
    }

    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
        if (inorderStart > inorderEnd || index >= n) return NULL;

        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in, element, n);
        
        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);

        return root;
    }

public:
    Node* buildTree(int in[], int pre[], int n) {
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
        return ans;
    }
};

int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n;
        cin >> n; // Read number of nodes
        
        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i]; // Read inorder array
        for (int i = 0; i < n; i++)
            cin >> preorder[i]; // Read preorder array

        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }

    return 0;
}
