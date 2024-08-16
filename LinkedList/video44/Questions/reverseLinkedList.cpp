#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int value){
        this -> data = value;  // Corrected
        this -> next = nullptr;
    }
};

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// reversing 
Node* reverse(Node* &head)  // Updated return type to Node*
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;  // Update head to new head of reversed list
    return head;  // Return the new head
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
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;

    cout << "List Before Reversing : " << endl;
    insertAtTail(tail, 26);
    insertAtTail(tail, 12);
    insertAtTail(tail, 37);
    insertAtTail(tail, 9);

    print(head);

    cout << "List After Reversing : " << endl;
    head = reverse(head);  // Corrected to assign the new head
    print(head);
}
