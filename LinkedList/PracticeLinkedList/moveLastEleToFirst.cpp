#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructpr
    Node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
};

void moveLast(Node* &head){

    if(head == NULL || head->next == NULL){
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr -> next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr -> next = head;
    head = curr;
    
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    cout <<"Original List: ";
    printList(head);
    cout << endl;
    cout << "List after moving last node to the front: ";
    moveLast(head);
    printList(head);
}