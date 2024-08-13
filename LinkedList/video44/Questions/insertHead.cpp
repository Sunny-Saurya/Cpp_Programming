#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;

    // constructor

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(ListNode* &head, int d)
{
    ListNode* newNode = new ListNode(d);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(ListNode* &tail, int d)
{
    ListNode* newNode = new ListNode(d);
    tail->next = newNode;
    tail = tail -> next;
}

void printNode(ListNode* head)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *node1 = new ListNode(11);
    ListNode *head = node1;
    ListNode *tail = node1;
    // printNode(head);

    cout  << "Adding to the head : " << endl;

    insertAtHead(head, 12);
    // printNode(head);
    insertAtHead(head, 13);
    // printNode(head);
    insertAtHead(head, 14);
    printNode(head);

    cout << endl;
    cout << "Adding to the tail : " << endl;


    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);
    printNode(head);

    
}