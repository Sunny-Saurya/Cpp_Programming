#include<bits/stdc++.h>
using namespace std;

class  Node{
    public:
    int data;
    Node* next;
    
    // constructo
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
};

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void print(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    insertAtTail(tail, 11);
    insertAtTail(tail, 13);
    
    print(head);
}