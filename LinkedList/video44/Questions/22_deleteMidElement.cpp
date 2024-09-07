#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void deleteMid(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int pos = (count / 2) + 1;

    Node *trac1 = head;
    Node *trac2 = head->next;
    
    for (int i = 0; i < pos - 2; i++)
    {
        trac1 = trac1->next;
        trac2 = trac2->next;
    }
    trac1->next = trac2->next;
    delete trac2;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);

    cout << "Original List: ";
    printList(head);

    deleteMid(head);
    cout << "List after deleting middle element: ";
    printList(head);
}
