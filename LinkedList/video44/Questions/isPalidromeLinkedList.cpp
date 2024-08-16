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

bool checkPalindrome(vector<int> ans) {
    int s = 0;
    int e = ans.size() - 1;

    while (s <= e) {
        if (ans[s] != ans[e]) return false;
        s++;
        e--;
    }
    return true;
}

bool isPalindrome(Node* &head) {
    vector<int> ans;
    Node* temp = head;

    while(temp != NULL) {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(ans);
}

int main() {
    Node* newNode = new Node(1);
    Node* tail = newNode;
    Node* head = newNode;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);

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
