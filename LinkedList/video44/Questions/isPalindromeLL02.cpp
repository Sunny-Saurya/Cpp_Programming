#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

Node* getMid(Node* head)
{
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow; // middle element
};

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head)
{
    if(head == NULL || head -> next == NULL) return true;

    // step 1. find the  middle element
    Node* middle = getMid(head);
    
    // step 2. reverse the second half
    Node* temp = middle -> next;
    middle -> next = reverse(temp);

    // step 3. Compare the both halves

    Node* head1  = head;
    Node* head2 = middle -> next;

    while(head2 != NULL)
    {
        if(head1 -> data  != head2 -> data )
        {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    // step 4 . restore the list
    temp = middle -> next;
    middle -> next = reverse(temp);


}

int main() {
    Node* newNode = new Node(1);
    Node* tail = newNode;
    Node* head = newNode;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    // insertAtTail(tail, 1);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Free the allocated memory (not required for the scope of this simple program)
    // but good practice in real applications.

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
