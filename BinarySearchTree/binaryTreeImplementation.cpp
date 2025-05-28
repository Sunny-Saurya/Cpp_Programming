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

Node* buildTree(Node* root){
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    // calling left of the tree
    cout << "Enter the data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter the data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

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

int main(){
    Node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
}