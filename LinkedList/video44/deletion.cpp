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

    // destructor
    ~Node(){
        int value = this->data;
        if(this -> next != NULL)
        {
            delete next;
            this-> next = NULL;
        }
        cout << "Memory  is free for node with data " << value << endl;
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

// Deletion of node using any position

void deleteNode(Node* &head, int pos)
{
    // deleting first or start node

    if(pos == 1)
    {
        Node* temp = head;

        head = head -> next;

        // memory free of start node

        temp -> next = NULL;
        delete temp;
    }

    else
    {
        // deleting any middle node or last node

        Node* curr = head;
        Node* prev = NULL;

        int count = 1;

        while (count < pos)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        
    }
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
    // print(head);

    InsertAtTail(tail, 15);
    // print(head);

    InsertAtPosition(tail,head, 4, 22);
    cout << "The original LL is : " << endl;
    print(head);

    cout << "The LL after deletion : "<< endl;
    deleteNode(head, 1);
    print(head);

    // cout << "head : " << head-> data << endl;
    // cout << "tail : " << tail -> data << endl;
}