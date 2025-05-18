#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = head;
    Node* newNode = new Node(data);

    temp -> prev = newNode;
    newNode -> next = temp;
    head = newNode;

}

void insertAtTail(Node* &tail, int data){
    Node* temp = tail;
    Node* newNode = new Node(data);

    temp -> next = newNode;
    newNode -> prev = temp;
    tail = newNode;

}

void insertAtMiddle(Node* &head, Node* &tail, int pos, int data){
    Node* temp = head;
    Node* newNode = new Node(data);
    Node* store = NULL;

    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    int cnt = 1;

    while(cnt < pos - 1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    store = temp -> next;
    temp -> next = newNode;
    newNode -> prev = temp;
    newNode -> next = store;
    store -> prev = newNode;
    
}

int getLength(Node* head){
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        cnt++;
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    return cnt;
}
void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

}
int main(){

    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;

    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtTail(tail, 12);
    insertAtTail(tail, 14);

    insertAtMiddle(head, tail, 6, 1000);
    printList(head);

    cout << "Length of LL : " << getLength(head) << endl;
    cout << "The head : " << head -> data << endl;
    cout << "The tail : " << tail -> data << endl;


}