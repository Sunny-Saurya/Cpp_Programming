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

// reversing kth element 

Node* kthReverse(Node* &head, int k)
{
    if(head == NULL || head -> next == NULL) return head;

    int count = 0;
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL && count < k){
        count++;
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    // recursively call

    if(next != NULL)
    {
        head -> next = kthReverse(next, k);
    }
    return prev;
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

    cout << "List Before Reversing : " << endl;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);

    print(head);

    int k;
    cout << "Enter number to reverse : " << " ";
    cin >> k;

    cout << "List After Reversing : " << endl;
    head = kthReverse(head,k);  // Corrected to assign the new head
    print(head);
}
