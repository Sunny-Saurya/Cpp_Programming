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

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}
void printList(Node* head){

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* node1 = new Node(1);
    Node* tail = node1;
    Node* head = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    // create loop for testing
    tail->next = node1;
    

    if(detectLoop(head)){
        cout << "\nLoop detected in the linked list" << endl;
    }
    else{
    cout << "Linked List: ";
        printList(head);
        cout << "\nNo loop detected in the linked list";
    }

}