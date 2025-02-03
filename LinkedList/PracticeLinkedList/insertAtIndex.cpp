#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node*&head, int d)
{
    Node* newNode = new Node(d);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}

void insertAtPos(Node* &head, int pos, int d)
{
    Node* newNode = new Node(d);

    if(pos == 1){
        insertAtHead(newNode, d);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(temp != NULL && count < pos - 1)
    {
        temp = temp -> next;
        count++;
    }
    

    if(temp == NULL){
        cout << "Position out of range" << endl;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

}

void print(Node* head)
{
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

    insertAtHead(head, 5);
    insertAtHead(head, 15);

    insertAtPos(head, 3, 355);
    print(head);

    
}