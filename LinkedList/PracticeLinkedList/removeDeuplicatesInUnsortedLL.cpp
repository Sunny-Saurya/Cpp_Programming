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

void insertAtTail(Node* &tail, int value){
    Node* newNode = new Node(value);
    tail -> next = newNode;
    tail = newNode;
}

Node* removeDuplicates(Node* &head){
    if(!head) return NULL;

    unordered_set<int> visited;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
       if(visited.find(temp -> data) == visited.end()){
            visited.insert(temp -> data);
            prev = temp;
       }
       else{
        prev -> next = temp -> next;
        delete temp;
        temp = prev -> next;
        continue;
       }
       temp = temp -> next;
    }
    return head;
}

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

}
int main()
{
    Node* node1 = new Node(20);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 10);
    insertAtTail(tail, 40);
    insertAtTail(tail, 10);
    insertAtTail(tail, 50);
    cout << "Original Linked List: ";
    printList(head);
    cout << endl;
    cout << " Linked List after removing duplicates: ";
    head = removeDuplicates(head);
    printList(head);
    return 0;


}