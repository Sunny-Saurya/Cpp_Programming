#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

Node* getMiddle(Node* head){
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right)
{
   if (!left) return right;
    if (!right) return left;

    Node* result = NULL;
    
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);  
    }
    
    return result;
}

Node* mergeSort(Node* head)
{
    if (head == NULL || head->next == NULL) return head;

    Node* mid = getMiddle(head);
    Node* leftPart = head;
    Node* rightPart = mid -> next;

    mid -> next = NULL;

    leftPart = mergeSort(leftPart);
    rightPart = mergeSort(rightPart);

    return merge(leftPart, rightPart);
}

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 6);
    insertAtTail(tail, 3);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);
}