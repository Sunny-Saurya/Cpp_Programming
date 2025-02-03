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

Node* startPointOfLoop(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            slow = head; 
            while(slow  != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }


    }

    return NULL;
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail( tail, 2);
    insertAtTail( tail, 3);
    insertAtTail( tail, 4);
    insertAtTail( tail, 5);
    insertAtTail( tail, 6);

    cout << "Tail : " << tail -> data  << endl;
    cout << "Head : " << head -> data << endl;

    tail -> next = head -> next -> next; // creating a loop
    Node* loopStart = startPointOfLoop(head);
    if(loopStart){
        cout << "Loop starts at node with value " << loopStart -> data << endl;
    }
    else{
        cout << "No loop found" << endl;
    }

}