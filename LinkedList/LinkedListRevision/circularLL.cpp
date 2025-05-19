#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &tail , int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode; 
}

void insertAtPosition(Node* head, Node* tail, int pos,  int data){
    
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    int count = 1;
    Node* temp = head;

    while(count < pos -1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

// 1st approach
bool isCircular(Node *head){
    Node* temp = head -> next;

    while(temp != NULL && temp != head){
        temp = temp -> next;
    }
    if(temp == head) return true;
    return false;
    
}

// 2nd approach
// bool isCircular(Node* head){

//     Node* slow = head;
//     Node* fast = head;

//     while(fast != NULL && fast -> next != NULL){
//         slow = slow -> next;
//         fast = fast -> next -> next;

//         if(slow == fast) return true;

//     }
//         return false;
// }

void printNode(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtHead(head, 16);
    insertAtTail(tail, 18);
    insertAtTail(tail, 19);
    insertAtTail(tail, 20);
    insertAtPosition(head, tail, 3, 1000);
    tail -> next = head;
    // printNode(head);

    if(isCircular(head)){
        cout << "Yes, This is Circular LL";
    }
    else{
        cout << "No, This is Not Circular LL";
    }

}