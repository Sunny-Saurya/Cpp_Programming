#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

void middleNode(Node* &head){
    int count = 0;
    Node* temp = head;

    while(temp != NULL){
        count++;
        temp = temp -> next;
    }

    int middle = count / 2;
    temp = head; 
    
    for(int i = 0; i < middle; i++){
        temp = temp -> next;
    }
    cout << "Middle Node is: " << temp -> data << endl;
}

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);
    cout << "Printing Linked List: ";
    printList(head);
    cout << endl;
    middleNode( head);
    return 0;
}