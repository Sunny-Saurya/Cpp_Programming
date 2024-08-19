#include<iostream>
#include<map>
using namespace std;

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

// Detect Loop

Node* detectLoop(Node* head)
{
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast -> next;

        if(fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast )
        {
            return slow;
        }
        
    }
    return NULL;
    
}

// finding  starting node of loop

Node* gettingStartingPoint(Node* head)
{
    if(head == NULL) return head;

    Node* intersection = detectLoop(head);
    if(intersection == NULL) return NULL;

    Node* slow = head;
    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection -> next;
    }
    return slow;
}


void print(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* newNode = new Node(1);
    Node* head = newNode;
    Node* tail = newNode;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);

    cout << "Tail data before creating loop: " << tail -> data << endl;
    tail -> next = head -> next -> next;  // Creating a loop for testing
    cout << "Head data: " << head  -> data << endl;

    // Check for loop
    
    if(detectLoop(head)){
        cout << "Loop detected " <<  endl;
    }else{
        cout << "No Loop detected" << endl;
    }

    // cheking the first Node of loop

    Node* startNode = gettingStartingPoint(head);
    
    if(startNode){
        cout << "Starting point of loop is " << startNode->data << endl;
    }
    else{
        cout << "No loop found" << endl;
    }
}
