#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int getLength(ListNode* headA)
    {
        ListNode* temp = headA;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int len1 = getLength(headA);
        int len2 = getLength(headB);

        int diff = abs(len1 - len2);
        ListNode* temp = headA;
         ListNode* temp2 = headB;

        if(len1 > len2){
            while(diff--) temp = temp -> next; 
        }
        else{
            while(diff--) temp2 = temp2 -> next;
        }

        while(temp != NULL && temp2 != NULL){
            if(temp == temp2 ){
                return temp;
            }
            temp = temp -> next;
            temp2 = temp2 -> next;
        }        

        return NULL;
    }
};