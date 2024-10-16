#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertIntoBST(Node* root, int d) {
    // base case
    if (root == nullptr) {
        return new Node(d);
    }

    if (d > root->data) {
        // go to right part
        root->right = insertIntoBST(root->right, d);
    } else {
        // go to the left part
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);  // updating the root with the returned value
        cin >> data;
    }
}

// printing the element by using level order traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of the current level
            cout << endl;
            if (!q.empty()) {
                // If there are more levels to process
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* maximumElement(Node* root) {
    Node* temp = root;

    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node* minimumElement(Node* root) {
    Node* temp = root;

    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    // base cases
    if (root == NULL) return root;

    if (root->data == val) {
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL) {
            int mini = minimumElement(root->right)->data;

            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    } else if (root->data > val) {
        // going to the left part
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        // going to the right part
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main() {
    Node* root = nullptr;
    cout << "Enter data to create BST (enter -1 to stop): " << endl;

    takeInput(root);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    if (root != nullptr) {
        cout << "Maximum element in the BST is: " << maximumElement(root)->data << endl;
    }

    root = deleteFromBST(root, 30);

    cout << "BST after deleting 30: " << endl;
    levelOrderTraversal(root);

    return 0;
}
