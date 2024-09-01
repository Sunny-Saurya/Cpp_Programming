#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, int d) {
    Node *newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

Node* mergeSort(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* temp = curr -> next;

    while(curr != NULL && temp != NULL){
        if(curr -> data < temp -> data){
            swap(curr -> data, temp -> data);
        }
        curr = curr -> next;
        curr -> next = temp;
        temp = prev;
        prev = curr;
    }
    return curr;
}


void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // First list
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 6);
    insertAtTail(tail, 3);

    cout << "Linked List: ";
    print(head);

    mergeSort(head);
    print(head);

    return 0;
}
