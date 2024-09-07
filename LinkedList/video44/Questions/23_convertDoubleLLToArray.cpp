#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:

    int data;
    Node *prev;
    Node *next;

    // constructor

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

};

void insertAtTail(Node* &tail, Node* &head , int d){
    Node* newNode = new Node(d);
    if(tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void convertingDoublyToArray(Node* head){
    Node* temp = head;
    vector<int> ans;
    while(temp != NULL){
        ans.push_back(temp->data);
        temp = temp -> next;
    };   
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 30);
    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 50);

    cout << "Original LinekdList : " <<  " ";
    printList(head);
    cout << "Doubly to an Array : " << " ";
    convertingDoublyToArray(head);
    cout << endl;


}