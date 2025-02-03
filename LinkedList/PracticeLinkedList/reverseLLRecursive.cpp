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

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

void reverseList(Node* &head, Node* prev = NULL) {
    if (head == NULL) {
        head = prev;  
        return;
    }

    Node* nextNode = head->next;  
    head->next = prev;           

    reverseList(nextNode, head);  
    head = nextNode;       
}
void printList(Node* &head)
{
    Node* temp = head;
    while (temp != NULL){
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
    cout << "Before Reverse : ";
    printList(head);

    cout << "After Reverse : ";
    reverseList(head);
    printList(head);



}