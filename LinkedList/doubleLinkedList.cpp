#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);
    newNode->next = temp;
    head = newNode;
}

Node *reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *doublingDigit(Node *head)
{
    head = reverseList(head);
    Node *temp = head;
    int carry = 0;
 
    while (temp != NULL)
    {
        int sum = temp -> data * 2 + carry;
        temp -> data = sum % 10;
        carry = sum / 10;

        if(temp -> next == NULL && carry){
            temp -> next = new Node(carry);
            carry = 0;
        }

        temp = temp->next;
    }
    head = reverseList(head);
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

    Node *node1 = new Node(9);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 2);
    insertAtHead(head, 4);

    head = doublingDigit(head);

    printList(head);
}