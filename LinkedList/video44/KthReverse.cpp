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

// Function to reverse every k nodes in the linked list
Node* KthReverse(Node* head, int k) {
    // Base case
    if (head == NULL) return NULL;

    // Step 1: Reverse first k nodes
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while (count < k && curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 2: Recursively reverse the rest of the list
    if (next != NULL) {
        head->next = KthReverse(next, k);
    }

    // Return the new head of the reversed list
    return prev;
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

    cout << "Original Linked List: ";
    printList(head);
    cout << endl;
    int k = 3;
    head = KthReverse(head, k);

    cout << "Reversed Linked List in groups of " << k << ": ";
    printList(head);

    return 0;
}
