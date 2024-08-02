#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

void  InsertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void InsertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
};

void print(Node *head){
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;

    }
    cout << endl;
}

void InsertAtPosition(Node* &tail ,Node* &head,int position, int d)
{
    // insert at start
    if(position == 1)
    {
        InsertAtHead(head,d);
        return;
    };
    

    Node* temp = head;
    int count  = 1;

    while(count < position-1)
    {
        temp = temp -> next;
        count++;
    }

    //inserting at last Position
    if(temp -> next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // creating a node for d

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

int main()
{
    // node
    Node* node1 = new Node(10);

    // cout << node1 -> data << endl;  // 0
    // cout << node1 -> next << endl;  // garbage value

    Node* head = node1;
    Node* tail =  node1;
    print(head);

    InsertAtTail(tail, 12);
    print(head);

    InsertAtTail(tail, 15);
    print(head);

    InsertAtPosition(tail,head, 4, 22);
    print(head);

    cout << "head : " << head-> data << endl;
    cout << "tail : " << tail -> data << endl;
}