
// You are using GCC
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    // constructor
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void insertAtTail(Node* &tail, int data)
{
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail ;
    tail = temp;
    
}

bool searchList(Node* &head, int key)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp -> data == key){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}


void print(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    int n;
    cin >> n;
    
    for(int i =0;i < n; i++)
    {
        int val;
        cin >> val;
        
        insertAtTail(tail,val);
    }
    int k;
    cin >> k;
    
    if(searchList(head,k)){
        cout << "Present in the list. ";
    }
    else{
        cout << "Not present in the list. ";
    }
    // cout << "AT The Tail : " << " ";
    // print(head);
    
}