#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

Node* insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

// checking loop using map 

bool detectLoop(Node* head)
{
    if(head == NULL) return false;
    Node* temp = head;

    map<Node*, bool> visited;

    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

void print(Node* head)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* node1 = new Node(12);
    Node* tail = node1;
    Node* head = node1;
    insertAtTail(tail,18);
    insertAtTail(tail,14);
    insertAtTail(tail,11);
    insertAtTail(tail,8);
    insertAtTail(tail,6);
    cout << tail -> data << endl;
    cout << head -> data << endl;

    tail -> next = head -> next;

    // print(head);

    if(detectLoop(head)){
        cout << "Loop is present" <<  " ";
    }
    else{
        cout << "Loop is not present" << " ";
    }
    
}