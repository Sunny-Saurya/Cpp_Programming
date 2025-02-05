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

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

Node* deleteDuplicates(Node* &head)
{
    if(!head) return NULL;

    Node* prev = NULL;
    Node* curr = head;
    Node* newNode;
    
    while(curr && curr -> next){
        if(curr -> data == curr -> next -> data){
            newNode = curr -> next;
            curr -> next = curr -> next -> next;
            delete newNode;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}

void print(Node* &head)
{
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    cout << "Printing before deletion" << endl;
    print(head);
    cout << endl;
    cout << "Printing after deletion" << endl;
    head = deleteDuplicates(head);
    print(head);
}