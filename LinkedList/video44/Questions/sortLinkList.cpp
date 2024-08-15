#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Insertion at the tail of the linked list
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Sorting the linked list containing 0s, 1s, and 2s
Node* sortList(Node* head) {
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    Node* temp = head;

    // First loop: Count the number of 0s, 1s, and 2s
    while(temp != NULL) {
        if(temp->data == 0) {
            countZero++;
        } else if(temp->data == 1) {
            countOne++;
        } else if(temp->data == 2) {
            countTwo++;
        }
        temp = temp->next; // Move to the next node
    }

    temp = head;

    // Second loop: Update the linked list according to the counts
    while(temp != NULL) {
        if(countZero != 0) {
            temp->data = 0;
            countZero--;
        } else if(countOne != 0) {
            temp->data = 1;
            countOne--;
        } else if(countTwo != 0) {
            temp->data = 2; // Corrected this line
            countTwo--;
        }
        temp = temp->next; // Move to the next node
    }
    
    return head;
}

// Print the linked list
void print(Node* head) {
    if(head == NULL) {
        return;
    }
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* newNode = new Node(1);
    Node* head = newNode;
    Node* tail = newNode;

    cout << "Before Sorting: " << endl;

    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);

    print(head);

    cout << "After Sorting: " << endl;

    sortList(head);
    print(head);

    return 0;
}
