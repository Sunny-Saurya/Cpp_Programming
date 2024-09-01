#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // contructor

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAttail(Node* &tail , int d)
{
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}
Node* reverse(Node* &head)
{
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while (curr != NULL)
    {
        next = curr->next; 
        curr->next = prev; 
        prev = curr;       
        curr = next;
    }
    return prev; 
}

void addingOne(Node* &head, Node* &head1)
{
    // head = reverse(head);
    Node* tempList = head;
    Node* tempList2 = head1;


    
    // tempList -> data = tempList -> data + tempList2 -> data;
    
    // return tempList;


    while (tempList -> next != NULL)
    {
        tempList = tempList -> next;
    }
    tempList -> data += tempList2 -> data;
    
    
}

void print(Node* head)
{
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

int main()
{

    Node* node1 = new Node(2);
    Node* head = node1;
    Node* tail = node1;

    insertAttail(tail,5);
    insertAttail(tail,2);

    cout << "Original List : " << " ";
    print(head);

    Node* node2 = new Node(1);
    Node* head1 = node2;
    Node* tail1 = node2;

    cout << "Updated List : " << " ";
    reverse(tail);
    addingOne(head, head1);
    print(head);




}