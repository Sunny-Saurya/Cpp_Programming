#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}

void deleteLast(Node* &head){
    Node* temp = head;
    while(temp -> next != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteFirst(Node* &head){
    
     if(head != NULL){ 
        Node* temp = head;    
        head = head->next;    
        delete temp;     

    }

}

void deleteAnyNode(Node* &head, int key)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp -> next -> data == key){
            Node*  temp2 = temp -> next;
            temp -> next = temp2 -> next;
            delete temp2;
            break;
        }
        temp = temp -> next;
    }
}



void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size: " << " ";
    cin >> n;

    Node* node1;
    Node* head ;
    Node* tail ;

    for(int i =0; i < n; i++){
        int val;
        cin >> val;
        if(i == 0)
        {
            node1 = new Node(val);
            head = node1;
            tail = node1;
        }
        else{

        insertAtTail(tail, val);
        }

    }
    // print(head);
    // cout << "Delete  last node" << " ";
    // deleteLast(head);
    // cout << endl;
    // cout << "delete first node : " << " ";
    // deleteFirst(head);
    // print(head);
    // cout << endl;

    int k;
    cout << "Enter key to delete: " << " ";
    cin >> k;

    deleteAnyNode(head, k);
    print(head);
}
