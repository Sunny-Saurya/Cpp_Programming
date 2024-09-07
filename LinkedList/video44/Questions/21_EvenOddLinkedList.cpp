#include <iostream>
#include <vector>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtTail(Node *&tail, int d) {
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void evenOddList(Node* &head) {
    vector<int> even;
    vector<int> odd;

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data % 2 != 0) {
            odd.push_back(temp->data);
        } else {
            even.push_back(temp->data);
        }
        temp = temp->next;
    }

    Node* dummy = new Node(0);
    Node* newList = dummy;

    // Append odd nodes
    for (int val : odd) {
        Node* newNode = new Node(val);
        newList->next = newNode;
        newList = newNode;
    }

    // Append even nodes
    for (int val : even) {
        Node* newNode = new Node(val);
        newList->next = newNode;
        newList = newNode;
    }

    head = dummy->next;
    delete dummy; 
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Ensure a newline after printing the list
}

int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    cout << "Original List: ";
    printList(head);

    evenOddList(head);

    cout << "Rearranged List (Odd first, then Even): ";
    printList(head);

    // Clean up memory
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
