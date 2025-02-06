#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // construtor
    Node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtTail(Node* &tail,int d){
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}

int addWithCarry(Node* head){
    if(head == NULL) return 1;
    int res = head -> data + addWithCarry(head -> next);
    head -> data = res % 10;
    return res/10;
}

Node* addOne(Node* head){
    int carry = addWithCarry(head);
    if(carry){
        Node* newNode = new Node(carry);
        newNode -> next = head;
        return newNode;
    }
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int  main()
{
    Node* node1 = new Node(9);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail,9);
    insertAtTail(tail,9);
    insertAtTail(tail,9);
    cout << "Original List: ";
    printList(head);
    cout << endl;
    cout << "Linked List after adding 1 at the end : ";
    head = addOne(head);
    printList(head);

}