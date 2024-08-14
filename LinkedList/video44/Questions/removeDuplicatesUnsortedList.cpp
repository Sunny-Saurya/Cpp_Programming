#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
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

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        Node *prev = curr;
        Node *temp = curr->next;

        while (temp != NULL)
        {
            if (temp->data == curr->data)
            {
                prev->next = temp->next; // Remove the duplicate node
                delete temp; // Free the memory
                temp = prev->next; // Move to the next node
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

void print(Node *head)
{
    if (head == NULL)
        return;

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
    Node *tail = newNode;
    Node *head = newNode;

    insertAtTail(tail, 61);
    insertAtTail(tail, 3);
    insertAtTail(tail, 71);
    insertAtTail(tail, 3);
    insertAtTail(tail, 62);
    insertAtTail(tail, 71);

    cout << "Before deletion of duplicate data : " << endl;
    print(head);

    cout << "After deletion of duplicate data : " << endl;
    removeDuplicates(head);
    print(head);
}