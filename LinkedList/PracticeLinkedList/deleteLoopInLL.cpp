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

Node* deleteLoop(Node* &head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            Node* loopStart = slow;

            while(fast -> next != loopStart){
                fast = fast -> next;
            }
            fast -> next = NULL;
            return head;
        }
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    tail -> next = head -> next ; // creatiing loop
    head = deleteLoop(head);
    print(head);
    

}