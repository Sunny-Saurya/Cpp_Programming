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

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}

// sorting of linked list

Node* sortList(Node* head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = head;

    // create diff- diff list for 0s, 1s, and 2s.

    while(temp != NULL)
    {
        int value = temp -> data;

        if(value == 0)
        {
            insertAtTail(zeroTail, value);
        }
        else if(value == 1)
        {
            insertAtTail(oneTail, value);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, value);
        }
        temp = temp -> next;
    }

    // merge 3 sublist

    if(oneHead -> next != NULL){  // if not 1s list is not empty
        zeroTail -> next = oneHead -> next;
    }
    else{ // 1s list --> empty
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    // setup Head

    head = zeroHead -> next;

    // delete dummy node;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}



// printing

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

    Node* node1  = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    cout << "Before sorting : " << endl;

    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);

    print(head);

    cout << "After sorting : " << endl;

    head = sortList(head);
    print(head);

}