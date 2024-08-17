#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Finding the mid of the linked list
Node* findMid(Node* head) {
    if (head == NULL) return head;

    Node* slow = head;
    Node* fast = head -> next;  // Correctly initialize the fast pointer

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function for merging the two linked lists
Node* merge(Node* left, Node* right) {
    if (right == NULL) return left;
    if (left == NULL) return right;

    Node* ans = new Node(-1); // Dummy node to simplify the merging process
    Node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    // Attach the remaining elements, if any
    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    Node* result = ans->next;
    delete ans;  // Clean up the dummy node
    return result;
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Break the linked list into two halves
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;  // Break the list

    // Recursive call for sorting the linked list
    left = mergeSort(left);
    right = mergeSort(right);

    // Now merge the two sorted linked lists
    Node* result = merge(left, right);
    return result;
}

void print(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a new node
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 52);
    insertAtTail(tail, 2);
    insertAtTail(tail, 32);
    insertAtTail(tail, 1);

    cout << "Before merge sort: " << endl;
    print(head);

    cout << "After merge sort: " << endl;
    head = mergeSort(head);
    print(head);

    return 0;
}
