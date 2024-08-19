#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

// reversing the list

Node* reverse(Node* &head)
{
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return prev;
}

// printing

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
int main()
{
    Node* node1 = new Node(10);
    Node* tail = node1;
    Node* head = node1;
    insertAtTail(tail, 21);
    insertAtTail(tail, 22);
    insertAtTail(tail, 30);
    insertAtTail(tail, 19);

    print(head);
    reverse(head);
    print(head);

}