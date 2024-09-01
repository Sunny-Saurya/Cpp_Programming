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

// delete Node

Node *nodeToRemove(Node *head, Node *head1)
{

    if (head == NULL)
        return head;
    if (head1 == NULL)
        return head;

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != NULL)
    {

        if (temp->data == head1->data)
        {
            if (prev == nullptr)
            {
                // node which you want to remove is in head

                head = temp->next;
            }
            else
            {
                // node which you want to remove is in the middle
                prev->next = temp->next;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    return NULL;
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

    Node *nodeToDelete = new Node(6);
    Node *head1 = nodeToDelete;
    Node *tail1 = nodeToDelete;

    nodeToRemove(head, head1);

    print(head);
}