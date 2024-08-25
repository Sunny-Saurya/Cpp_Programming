#include<iostream>
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

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* intersectionPoint(Node* head, Node* head1) {
    int len1 = getLength(head);
    int len2 = getLength(head1);

    // Adjust the starting points
    Node* temp1 = head;
    Node* temp2 = head1;

    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) {
            temp1 = temp1->next;
        }
    } else if (len2 > len1) {
        int diff = len2 - len1;
        while (diff--) {
            temp2 = temp2->next;
        }
    }

    // Move both pointers and check for intersection
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    //node1
    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 1);
    insertAtTail(tail, 8);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    cout << "LinkedList I: " << endl;
    cout << "tail :  " << tail -> data << endl;
    print(head);

    // node2
    Node* node2 = new Node(5);
    Node* head1 = node2;
    Node* tail1 = node2;

    tail -> next = tail1;

    insertAtTail(tail1, 6);
    insertAtTail(tail1, 1);
    insertAtTail(tail1, 8);
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 5);

    cout << "LinkedList II: ";
    print(head1);

    Node* intersection = intersectionPoint(head, head1);
    if (intersection) {
        cout << "Yes, there is an intersection at node with data: " << intersection->data << endl;
    } else {
        cout << "No, there is no intersection." << endl;
    }

    return 0;
}
