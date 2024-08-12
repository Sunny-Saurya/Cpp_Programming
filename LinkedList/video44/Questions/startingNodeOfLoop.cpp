#include <iostream>
#include<map>
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

void  InsertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void InsertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
};

void print(Node *head){
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;

    }
    cout << endl;
}

void InsertAtPosition(Node* &tail ,Node* &head,int position, int d)
{
    // insert at start
    if(position == 1)
    {
        InsertAtHead(head,d);
        return;
    };
    

    Node* temp = head;
    int count  = 1;

    while(count < position-1)
    {
        temp = temp -> next;
        count++;
    }

    //inserting at last Position
    if(temp -> next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // creating a node for d

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

bool detectLoop(Node* head)
{
    if(head == NULL) return false;

    map<Node*,bool> visited;

    Node* temp  = head;

    while(temp != NULL)
    {
        // cycle is present
        if(visited[temp] == true) 
        {
        cout << "Cycle starts from : " << temp -> data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;

    }
    return false;
}

// flydsDetectLoop

Node* floydDetectLoop(Node* head)
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

        if(slow == fast)
        {
            cout << "Present at " << fast -> data << endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head)
{
    if(head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);

    Node* slow = head;

    while (slow != intersection)
    {
        /* code */
        slow = slow -> next;;
        intersection = intersection -> next;
    }
    return slow;
    

}

int main() {
    Node* node1 = new Node(10);
    Node* head =  node1;
    Node* tail = node1;

    InsertAtPosition(tail, head, 2, 12);
    InsertAtPosition(tail, head, 3, 14);
    InsertAtPosition(tail, head, 4, 16);
    InsertAtPosition(tail, head, 5, 18);

    tail -> next = head -> next;
    // print(head);

    if(floydDetectLoop(head)) cout << "Cycle is present";
    else cout << "Cycle is not present";

    if(getStartingNode(head))
    {
        cout << "Starting node of cycle is " << getStartingNode(head)->data << endl;
    }
    else{
        cout << "No cycle is present" << endl;
    }

    return 0;
}
