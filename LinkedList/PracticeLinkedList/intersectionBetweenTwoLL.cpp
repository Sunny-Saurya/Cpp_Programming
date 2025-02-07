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

void insertAtTail(Node* &tail, int n){
    Node* newNode = new Node(n);
    tail->next = newNode;
    tail = newNode;
};

// get length of linked list
int getLength(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}

Node* intersectTwoLinkedList(Node * &head1, Node* &head2){

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    Node* temp1 = head1;
    Node* temp2 = head2;

    if(len1 > len2){
        while(diff--) temp1 = temp1 -> next;
    }
    else{
        while(diff--) temp2 = temp2 -> next;
    }

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2){
            return temp1;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return NULL;

}

void printList(Node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
}
int main() {
    
    Node* node1 = new Node(1);
    Node* head1 = node1;
    Node* tail1 = node1;
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 6);

    Node* node2 = new Node(9);
    Node* head2 = node2;
    Node* tail2 = node2;
    insertAtTail(tail2, 10);

    tail2->next = head1->next->next->next;  

    cout << "First Linked List: ";
    printList(head1);

    cout << "Second Linked List: ";
    printList(head2);

    // Find intersection
    Node* intersection = intersectTwoLinkedList(head1, head2);

    if (intersection) {
        cout << "Intersection found at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;


}