#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* BuildTree(Node* root){
    cout << "Enter the node: "<< endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout << "Enter left Node of "<< root -> data << endl;
    root -> left = BuildTree(root -> left);

    cout << "Enter right Node of " << root -> data << endl;
    root -> right = BuildTree(root -> right);

    return root;
}


void levelOrderTraversal(Node* root){
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
            
        }

        else{
            cout << temp -> data << " ";

            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

int height(Node* root){
    if(root == NULL) return 0;
    
    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right)+1;
    return ans;
}

bool isBalancedTree(Node* root){

    if(root == NULL) return true;

    bool left = isBalancedTree(root -> left);
    bool right = isBalancedTree(root -> right);

    bool diff = abs(height(root -> left) - height(root -> right) <= 1);

    if(left && diff && right){
        return true;
    }
    else{
        return false;
    }

}


bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        if(r1 == NULL && r2 == NULL) return true;
        
        if(r1 == NULL && r2 != NULL) return false;
        
        if(r1 != NULL && r2 == NULL) return false;
        
        bool left = isIdentical(r1-> left, r2 -> left);
        bool right = isIdentical(r1 -> right, r2 -> right);
        
        bool value = r1 -> data == r2 -> data;
        
        if(left && value && right){
            return true;
        }
        else{
            return false;
        }
    }

int main(){
    Node* root = NULL;
root = BuildTree(root);
levelOrderTraversal(root);

if(isBalancedTree){
    cout << "Yes this is Balanced!!";
}
else{
    cout << "Not Balanced !!";
}

    

// 1 2 3 4 5 -1 -1  1
// 1
// 2
// 4
// -1
// -1
// 5
// -1
// -1
// 3
// -1
// -1

}