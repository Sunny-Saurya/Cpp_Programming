    #include<bits/stdc++.h>
    using namespace std;

    class Node{
        public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    };

    void insertAtHead(Node* &head, int data){
        Node* newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
    }

    void insertAtTail(Node* &tail , int data){
        Node* newNode = new Node(data);
        tail -> next = newNode;
        tail = newNode; 
    }

    void insertAtPosition(Node* head, Node* tail, int pos,  int data){
        
        if(pos == 1){
            insertAtHead(head, data);
            return;
        }

        int count = 1;
        Node* temp = head;

        while(count < pos -1){
            temp = temp -> next;
            count++;
        }

        if(temp -> next == NULL){
            insertAtTail(tail, data);
            return;
        }

        Node* newNode = new Node(data);
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    Node* reverse(Node* head){

        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;

        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;

    }

  void reverseRecursively(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverseRecursively(head, forward, curr);
    curr -> next = prev;
}


Node* reverseRecursively2(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* subProb = reverseRecursively2(head -> next);
    head -> next -> next  = head;
    head -> next = NULL;

    return subProb;
}
    void printNode(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }


    int main(){

        Node* node1 = new Node(10);
        Node* head = node1;
        Node* tail = node1;

        Node* prev = NULL;
        Node* curr = head;

        insertAtHead(head, 12);
        insertAtHead(head, 14);
        insertAtHead(head, 16);
        insertAtTail(tail, 18);
        insertAtTail(tail, 19);
        insertAtTail(tail, 20);
        insertAtPosition(head, tail, 3, 1000);
        cout << "Before Reversal : ";
        printNode(head);
        cout << "The head : " << head -> data << endl;
        cout << "The tail : " << tail -> data << endl;
        cout << endl;
        cout << "After Reversal : ";
        // head = reverse(head);

        head = reverseRecursively2(head);
        printNode(head);

        cout << "The head : " << head -> data << endl;
        cout << "The tail : " << tail -> data << endl;
    }