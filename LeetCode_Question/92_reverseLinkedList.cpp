#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    ListNode* reverse(ListNode* head){
        if(head == NULL) return head;

        // ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* newNode;

        while(curr != NULL){
            newNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = newNode;
        }

        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i = 1; i < left; i++){
            prev = prev -> next;
        }

        ListNode* start = prev -> next;
        ListNode* nextNode = start;
        ListNode* sublistPrev = NULL;

        for(int i = left; i <= right; i++){
            ListNode* temp = nextNode -> next;
            nextNode -> next = sublistPrev;
            sublistPrev  = nextNode;
            nextNode = temp;
        }
        start -> next = nextNode;
        prev -> next = sublistPrev;

        return dummy -> next;
    }
};
