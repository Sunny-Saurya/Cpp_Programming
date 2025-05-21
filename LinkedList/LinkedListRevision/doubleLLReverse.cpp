#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = head;

    Node *newNode = new Node(data);

    temp -> prev = newNode;
    newNode -> next = temp;
    head  = newNode;
}

Node* reverseDLL(Node* &head){

    Node* temp = head;
    Node* forward = NULL;

    while(temp != NULL){
        forward = temp -> prev;
        temp ->prev = temp -> next;
        temp -> next =  forward;
        temp = temp -> prev;
    }
    return head;

}

void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *newNode = new Node(10);
    Node *head = newNode;
    insertAtHead(head, 12);
    insertAtHead(head, 15);
    insertAtHead(head, 18);
    head = reverseDLL(head);
    printList(head);
    cout << endl;
}