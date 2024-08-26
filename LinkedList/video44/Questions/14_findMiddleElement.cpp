#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // contructor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// I approach --->>>>

Node *getMiddle(Node *head)
{

    if (head == NULL)
        return head;
    Node *slow = head;
    Node *fast = head -> next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next -> next;
    }

    return slow;
}


void print(Node *head)
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
    Node *node = new Node(2);
    Node *head = node;
    Node *tail = node;

    insertAtTail(tail, 4);
    insertAtTail(tail, 6);
    insertAtTail(tail, 1);
    insertAtTail(tail, 5);
    insertAtTail(tail, 8);
    insertAtTail(tail, 4);

    cout << "Linked list : " << " ";
    print(head);
    
    Node *mid = getMiddle(head);
    if (mid)
    {
        cout << "Mid of Linked List : " << mid->data << endl;
    }
}