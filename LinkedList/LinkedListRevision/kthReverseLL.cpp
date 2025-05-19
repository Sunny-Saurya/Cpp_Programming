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

Node* kthReverse(Node* &head, int k){
    if(head == NULL) return head;

    //  for first k element

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    int count = 0;

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // recursive for rest element

    if(next != NULL){
        head -> next = kthReverse(next, k);
    }

    return prev;

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

    head = kthReverse(head,3);
    printNode(head);

    cout << "The head : " << head -> data << endl;
    cout << "The tail : " << tail -> data << endl;
}