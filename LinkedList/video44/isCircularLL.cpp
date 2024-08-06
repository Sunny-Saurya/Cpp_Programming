#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

bool isCircularList(Node* head)
{
    // empty list
    if (head == NULL) {
        cout << "List is empty" << endl;
        return true;
    }

    Node* temp = head->next;
    while (temp != NULL && temp != head)
    {
        cout << "Visiting node with data: " << temp->data << endl;
        temp = temp->next;
    }

    if (temp == head) {
        cout << "Found a cycle returning to head." << endl;
        return true;
    }

    cout << "No cycle found." << endl;
    return false;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);

    if (isCircularList(head)) {
        cout << "Linked List is Circular" << endl;
    } else {
        cout << "Linked List is not Circular" << endl;
    }

    return 0;
}
