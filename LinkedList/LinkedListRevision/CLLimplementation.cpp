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

void insertNode(Node *&tail, int element, int data)
{
    // assuming that there is only one element in the LL

    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {

        // for the remaining cases like 2 , 3, 4...
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void deleteNode(Node *&tail, int element)
{
    Node *prev = tail;
    Node *curr = tail->next;

    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    if(curr == prev){
        tail = NULL;
    }

    if(tail == curr){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}

void printList(Node *&tail)
{
    Node *temp = tail;

    if(tail == NULL){
        cout << "List is Empty..";
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
}

int main()
{

    Node *tail = NULL;

    insertNode(tail, 10, 12);
    // insertNode(tail, 12, 14);
    // insertNode(tail, 14, 16);

    cout << "Before Deletion : ";
    printList(tail);
    deleteNode(tail, 10);

    cout << endl;
    cout << "After deletiong : ";
    printList(tail);
}