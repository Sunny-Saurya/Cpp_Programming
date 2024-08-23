// remove duplicates form a sorted Linked List

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
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

// Remove duplicates

Node* removeDuplicates(Node* &head)
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
    Node* tail = node1; 
    Node* head = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 12);
    insertAtTail(tail, 23);
    insertAtTail(tail, 34);
    insertAtTail(tail, 34);
    insertAtTail(tail, 45);
    insertAtTail(tail, 51);

    cout << " Original Linked List : " << endl;
    print(head);

    cout << "Updated Linked List : " << endl;
    removeDuplicates(head);
    print(head);
}