#include<bits/stdc++.h>

using namespace std; 

class Solution {
    private:
Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next; // Store next node
            curr->next = prev; // Reverse the link
            prev = curr; // Move prev forward
            curr = next; // Move curr forward
        }
        return prev; // New head of reversed list
    }
  public:
    // Function to check whether the list is palindrome.
     bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL)
            return true; // Empty list or single node is always palindrome
        
        // Step 1: Find the middle of the linked list using slow & fast pointers
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half
        Node* secondHalf = reverse(slow);
        Node* firstHalf = head;
        Node* temp = secondHalf; // To restore the list later

        // Step 3: Compare the first and second halves
        while (secondHalf != NULL) {
            if (secondHalf->data != firstHalf->data) {
                reverse(temp); // Restore the second half before returning
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: Restore the original structure of the list
        reverse(temp);
        return true;
    }
};