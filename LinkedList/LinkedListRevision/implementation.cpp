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
    
    int count = 1;
    Node* temp = head;

    while(count < pos -1){
        temp = temp -> next;
        count++;
    }

    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

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
    printNode(head);

    cout << "The head : " << head -> data << endl;
    cout << "The tail : " << tail -> data << endl;
}