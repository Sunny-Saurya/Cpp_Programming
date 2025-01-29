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

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}


void print(Node* node)
{
    while(node != NULL){
        cout << node -> data << " ";
        node = node -> next;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    cout << "Head : " << head -> data << endl;
    insertAtHead(head, 20);
    // print(head);
    insertAtHead(head, 30);
    print(head);
    cout << "head : " << head -> data << endl;

    cout << endl;
}