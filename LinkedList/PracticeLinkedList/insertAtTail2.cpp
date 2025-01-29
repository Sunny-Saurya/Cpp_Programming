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

void insertAtTail(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = NULL;
    
    
    
    // else
    
    Node* current = head;
    while(current -> next != NULL)
    {
        current = current -> next;
    }
    
    current -> next = temp;

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
    
    insertAtTail(head, 11);
    insertAtTail(head, 13);
    
    print(head);
}