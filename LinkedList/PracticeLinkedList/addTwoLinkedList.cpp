#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}


Node* sumOfLinkedList(Node* head1, Node* head2){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int carry = 0;
    

    while(head1 != NULL || head2 != NULL || carry != 0){
        int sum = carry;
        if(head1 != NULL){
            sum += head1 -> data;
            head1 = head1 -> next;
        }
        if(head2 != NULL){
            sum += head2 -> data;
            head2 = head2 -> next;
        }
        temp -> next = new Node( sum % 10);
        // carry = sum / 10;
        temp = temp -> next;
    }
    return dummy -> next;
}


void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}



int main()
{
    // take two linked list
    Node* node1 = new Node(1);
    Node* tail1 = node1;
    Node* head = node1;
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 3);

    Node* node2 = new Node(4);
    Node* tail2 = node2;
    Node* head2 = node2;
    // insertAtTail(tail2, 5);
    insertAtTail(tail2, 7);
    cout << "First Linked List: ";
    printList(head);
    cout << endl;
    cout << "Second Linked List: ";
    printList(head2);
    cout << endl;

    head = sumOfLinkedList(head, head2);
    cout << "Sum of Linked List: "; 
    printList(head);
    return 0;
    
}