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

void insertAtPos(Node* &head, int data, int pos)
{
    Node* node1 = new Node(data);
    
    // if the pos == 1
    if(pos == 1){
        node1 -> next = head;
        head = node1;
        return;
    }

    Node* temp  = head;
    int count = 1;

    while(temp != NULL && count < pos - 1)
    {
        temp = temp -> next;
        count++;
    }

    if(temp == NULL) {
        cout << " Invalid position" << endl;
        return;
    }

    node1 -> next = temp -> next;
    temp -> next = node1;
}

void printList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* node1 = new Node(10);
    node1 -> next = new Node(20);
    node1 -> next -> next = new Node(30);
    node1 -> next -> next -> next = new Node(40);
    node1 -> next -> next -> next -> next = new Node(50);
    Node* head = node1;
    insertAtPos(head, 25, 3);
    printList(head);
}