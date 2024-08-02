#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor

    Node(int d)
    {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

// traversing a linked list

void print(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;

    }
    cout << endl;
}

// length of linked list

int getLength(Node* head)
{
    Node* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;

    }   
    return count;
    cout << endl;
}

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev  = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    Node*temp1 = new Node(d);
    tail -> next = temp1;
    temp1 -> prev = tail;
    tail = temp1;

}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    cout << "Length is : "<<  getLength(head) << endl;

    insertAtTail( tail, 12);
    insertAtTail( tail, 14);
    insertAtTail( tail, 16);
    insertAtTail( tail, 17);
    print(head);
    cout << "Length is : "<<  getLength(head) << endl;
}