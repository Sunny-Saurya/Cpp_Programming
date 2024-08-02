#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// traversing a linked list

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

// length of linked list

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
    cout << endl;
}

void insertAtHead(Node* &tail , Node *&head, int d)
{

    // for empty list

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node *&head, int d)
{

    if (tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{

    if (pos == 1)
    {
        insertAtHead(head,tail, d);
        return;
    }

    else
    {
        Node* temp = head;
        int count = 1;

        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        // insert at  last position

        if (temp->next == NULL)
        {
            insertAtTail(tail,head, d);
            return;
        }

        // creating a node for d;

        Node *nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}

int main()
{
    // Node *node1 = new Node(10);
    // Node *head = node1;
    // Node *tail = node1;

    // if node head and tail is NULL at start then how to insert

    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    // cout << "Length is : " << getLength(head) << endl;

    insertAtTail(tail,head, 12);
    insertAtTail(tail,head, 14);
    insertAtTail(tail,head, 16);
    insertAtTail(tail,head, 17);
    print(head);

    insertAtPos(head, tail, 5, 111);
    print(head);

    cout << "Length is : " << getLength(head) << endl;
}