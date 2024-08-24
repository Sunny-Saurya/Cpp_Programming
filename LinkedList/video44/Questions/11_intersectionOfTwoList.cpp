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

int getLength(Node *head) {
    int length = 0;
    Node *temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

Node *intersectionNode(Node *head, Node *head1) {
    int len1 = getLength(head);
    int len2 = getLength(head1);

    // Align the starting point of both lists
    while (len1 > len2) {
        head = head->next;
        len1--;
    }
    while (len2 > len1) {
        head1 = head1->next;
        len2--;
    }

    // Traverse both lists to find the intersection
    while (head != NULL && head1 != NULL) {
        if (head == head1) {
            return head;
        }
        head = head->next;
        head1 = head1->next;
    }
    return NULL; // No intersection found
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
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    cout << "First List: ";
    print(head);

    // Second list
    Node *node2 = new Node(6);
    Node *head1 = node2;
    Node *tail1 = node2;
    insertAtTail(tail1, 7);
    insertAtTail(tail1, 8);

    // Creating an intersection
    tail1->next = head->next->next; // Point to the node with data 3 in the first list

    cout << "Second List: ";
    print(head1);

    Node *intersectingNode = intersectionNode(head, head1);

    if (intersectingNode != NULL) {
        cout << "Intersection at node with data: " << intersectingNode->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
