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

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;

    cout << "Enter data for root : ";
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter the left data of " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter the right data of " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
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

int heightOfTree(Node* root){
    if(root == NULL) return 0;

    int left = heightOfTree(root -> left);
    int right = heightOfTree(root -> right);

    return max(left , right) + 1;
}

int diameterOfTree(Node* root){
    if(root == NULL) return 0;

    int left = diameterOfTree(root -> left);
    int right = diameterOfTree(root -> right);
    int leftRight = heightOfTree(root -> left) + heightOfTree(root -> right) + 1;

    int ans = max(max(left, right), leftRight);
    return ans;
}


int main(){
    Node* root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    cout << "The height of tree is : " << heightOfTree(root) << endl;
}
