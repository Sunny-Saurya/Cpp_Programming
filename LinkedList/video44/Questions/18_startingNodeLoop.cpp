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

Node *detectCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
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
}

int main()
{
    Node *node1 = new Node(1);
    Node *tail = node1;
    Node *head = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);

    tail->next = head -> next;
    Node *startPoint = detectCycle(head);
    if (startPoint != NULL)
    {
        cout << "Cycle detected at node " << startPoint->data << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }
    // cout << endl;
    // print(head);
}