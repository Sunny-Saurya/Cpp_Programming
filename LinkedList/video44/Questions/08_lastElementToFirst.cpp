#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int value){
        this -> data = value;
        this -> next = nullptr;
    }
};

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void moveToFront(Node* &head) 
{ 
    if (head == NULL || head->next == NULL) {
        // List is empty or has only one node
        return;
    }

    Node* secondLast = NULL;
    Node* last = head;

    // Traverse to find the last node and the second last node
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }

    // Update the pointers
    secondLast->next = NULL;  // Remove link to the last node
    last->next = head;        // Move last node to front
    head = last;   
} 

void print(Node* head)
{
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
    Node* newNode = new Node(1);
    Node* head = newNode;
    Node* tail = newNode;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);

    cout << "Original List : " << endl;
    print(head);

    cout << "Updated List : " << endl;
    moveToFront(head);
    print(head);
}
