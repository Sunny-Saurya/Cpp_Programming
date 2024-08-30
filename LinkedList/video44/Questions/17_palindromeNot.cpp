#include<iostream>
#include<vector>
using  namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int value){
        this -> data = value;
        this -> next = nullptr;
    }
};

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

bool checkPalindrome(vector<int> arr)
{
    int s = 0;
    int e = arr.size() -1;

    while(s <= e)
    {
        if(arr[s] != arr[e]) return false;
        {
            s++;
            e--;
        }
    }
    return true;
}


bool isPalindrome(Node* &head)
{
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL)
    {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    return checkPalindrome(arr);
}


int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

}