#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &tail , int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode; 
}

void insertAtPosition(Node* head, Node* tail, int pos,  int data){
    
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    int count = 1;
    Node* temp = head;

    while(count < pos -1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

int getLength(Node* head){
    int count = 1;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}

Node* middleLL(Node* head){
    int count = 1;
    Node* temp = head;
    while(count < getLength(head) / 2){
        temp = temp -> next;
        count++;
    }
    return temp;
}

Node* getMiddleElement(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    // for 2 element
    if(head -> next ->next == NULL){
        return head -> next;
    }

    // rest n element

    Node* fast = head -> next;
    Node* slow = head;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;
    }

    return slow;
}

void printNode(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtHead(head, 16);
    insertAtTail(tail, 18);
    insertAtTail(tail, 19);
    // insertAtTail(tail, 20);
    insertAtPosition(head, tail, 3, 1000);
    cout << "Elements of LL :";
    printNode(head);
    cout << endl;

    Node* middleElement = getMiddleElement(head);
    cout << "The middle element is : " << middleElement -> data << endl;

    cout << "The head : " << head -> data << endl;
    cout << "The tail : " << tail -> data << endl;
}