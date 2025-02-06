#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    // construtor
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

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

bool isPalindrome(Node* &head)
{
    // find middle of linked list
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

    }
    Node* secondHalf = reverse(slow);
    Node* firstHalf = head;

    Node* temp = secondHalf;
    while(secondHalf != NULL){
        if(firstHalf -> data != secondHalf -> data){
            reverse(temp);
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    reverse(temp);
    return true;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    cout << "Linked List: ";
    printList(head);
    cout << endl;

    if(isPalindrome(head)){
        cout << "Linked List is a Palindrome" << endl;
    }
    else{
        cout << "Linked List is not a Palindrome" << endl;
    }

}