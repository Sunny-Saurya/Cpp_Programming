#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int value){
        this -> data = value;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &tail, int value){
    Node* temp = new Node(value);
    tail -> next = temp;
    tail = temp;
}


void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* newNode;

    while(curr  != NULL){
        newNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = newNode;
    }
    head = prev;


}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{

    Node* node1 = new Node(1);
    Node* tail = node1;
    Node* head = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    cout << "Linked List Before Reverse : ";
    print(head);
    reverse(head);
    cout << endl;
    cout << "Linked List After Reverse : ";
    print(head);

}