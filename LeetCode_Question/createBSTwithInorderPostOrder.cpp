#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(Node* node) {
    if (node == NULL)
        return;

    // Print the data of the node
    cout << node->data << " ";

    // Recur on left child
    preOrder(node->left);

    // Recur on right child
    preOrder(node->right);
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

    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n) {
        if (inorderStart > inorderEnd || index < 0) return NULL;

        int element = post[index--];
        Node* root = new Node(element);
        int position = findPosition(in, element, n);
        
        // Recursively construct the right and left subtrees
        root->right = solve(in, post, index, position + 1, inorderEnd, n);
        root->left = solve(in, post, index, inorderStart, position - 1, n);
        
        return root;
    }

public:
    Node* buildTree(int n, int in[], int post[]) {
        int postOrderIndex = n - 1;
        Node* ans = solve(in, post, postOrderIndex, 0, n - 1, n);
        return ans;
    }
};

int main() {
    int t, n;
    cin >> t; // Read number of test cases
    while (t--) {
        cin >> n; // Read number of nodes
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i]; // Read inorder array
        for (int i = 0; i < n; i++)
            cin >> post[i]; // Read postorder array
        
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root); // Print pre-order traversal of the constructed tree
        cout << endl;
    }
    return 0;
}
