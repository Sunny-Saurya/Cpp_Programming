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

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

bool isCircular(Node* &head){
    if(head == NULL) return true;

    if(head -> next == head) return true;

    Node* temp  =  head;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    return temp == head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
};


int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    tail -> next = head;
    
    if(isCircular(head)){
        cout << "The linked list is circular" << endl;
    }
    else{
        cout << "The linked list is not circular" << endl;
    }

}