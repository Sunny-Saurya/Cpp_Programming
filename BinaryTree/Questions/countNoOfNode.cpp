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

// Building the tree
Node* buildTree(Node* &root) {
    cout << "Enter the data: ";
    int data;
    cin >> data;

    if(data == -1) {
        return NULL; // End of branch
    }

    root = new Node(data);    
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// Level-order (breadth-first) traversal of the tree
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

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
        } else {
            cout << temp->data << " ";  // Print the data at this node
            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int inOrder(Node* root, int &count)
{
    if(root == NULL) return 0;
    inOrder(root -> left, count);
    if(root -> left == NULL && root -> right == NULL){
        count++;
    }
    inOrder(root -> right, count);
    return count;
}

int countNoOfLeaf(Node* root)
{
    int count = 0;
    inOrder(root, count);
    return count;
}

int main() {
    Node* root = NULL;
    
    // Build the tree
    buildTree(root);

    // Perform level-order traversal (BFS)
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << "No. of Leafs present in this  tree: " << countNoOfLeaf(root) << endl;

    return 0;
}
