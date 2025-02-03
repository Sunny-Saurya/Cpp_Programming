#include<bits/stdc++.h>
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

Node* reverse(Node* &head, int k)
{
    // base case
    if(head == NULL) return head;
    
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode;
    int count = 0;
    while(curr != NULL && count < k){
        nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }
    
    if(nextNode != NULL){
        head -> next = reverse(nextNode, k);
    }
    
    return prev;
}
void print(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    
    int k ;
    cout << "Enter k";
    cin >> k;
    cout << "Before Reverse: ";
    print(head);
    
    cout << "Reverse ";
    head = reverse(head,k);
    print(head);
    cout << "Head : " << head -> data;
    cout << "Tail : " << tail -> data;
}