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

// converting binary to an integer number

int  binaryToDecimal(Node* head){
    Node* temp = head;
    int decimal = 0;

    while(temp != NULL){
        decimal = decimal * 2 + temp -> data;
        temp = temp -> next;
    }
    return decimal;
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
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    cout << "Linked List: " << " ";
    print(head);
    cout << endl;
    
    cout << "List after convertion (binary to integer) is : " <<  binaryToDecimal(head) << endl;
}