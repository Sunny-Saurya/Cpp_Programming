#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Creating tree
Node* buildTree(Node* &root) { // Pass root by reference
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    if(data == -1) return NULL; // Handle -1 case first
    
    root = new Node(data);
    
    cout << "Enter left node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right node of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Printing tree level-order (BFS)
void buildFromLevelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";  // Print the data

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;
    buildTree(root);  // Call by reference
    // Example input: 1 3 5 -1 -1 7 -1 -1 2 6 -1 -1 8 -1 -1
    buildFromLevelOrder(root);  // Level-order traversal
    return 0;
}
