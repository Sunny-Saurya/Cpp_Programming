// This is the code for deletion of the same data in sorted linked list.

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

Node*  removeDuplicates(Node* head)
{
    if(head == NULL) return NULL;

    Node* curr = head;

    while(curr != NULL)
    {
        if((curr -> next != NULL) && curr -> data == curr -> next -> data)
        {
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}

void print(Node* head)
{
    if(head == NULL) return;

    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;

    insertAtHead(head, 9);
    insertAtHead(head, 4);
    insertAtHead(head, 4);
    insertAtHead(head, 2);
    insertAtHead(head, 2);

    cout << "Before deletion of duplicate data : " << endl;
    print(head);

    cout << "After deletion of duplicate data : " << endl;
    removeDuplicates(head);
    print(head);
}