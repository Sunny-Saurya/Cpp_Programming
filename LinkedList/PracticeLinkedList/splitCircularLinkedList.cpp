#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    // construtor
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAtTail(Node *&tail, int d)
{
    Node *newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}



void splitCircularList(Node* &head)
{
    if(head == NULL || head -> next == NULL) return;
    Node *slow = head;
    Node *fast = head;
    for(fast -> next != NULL && fast -> next -> next != head){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    if(fast -> next -> next == head) {
        fast = fast -> next;
    }
    
    Node* first = head;
    Node* second = slow -> next;
    slow -> next = head;
    
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()

{
}