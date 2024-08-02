#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    // descturctor

    ~Node()
    {
        int value = this -> data;
        if(this->next != NULL)
        {
            delete next;
            next =  NULL;
        }
        cout << "Memory is free for node with data : " << value << endl;

    }
};

void insertNode(Node* &tail, int element, int d)
{
    // assuming that the elment is present in the list

    // empty list
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }

    else
    {
        // non empty list

        Node* curr = tail;

        while(curr -> data != element)
        {
            curr = curr -> next;
        }

        // element found -> curr is representing element wala node

        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* &tail)
{
    Node* temp = tail;  

    // empty list;

    if(tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    } while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value)
{
    // empty list
    if(tail == NULL)
    {
        cout << "LIst is empty, please check again " << endl;
        return;
    }

    else
    {
        // non empty

        // assuming that value is present in the LL.

        Node *prev = tail;
        Node * curr = prev -> next;

        while(curr -> data != value)
        {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        // 1 node linked list
        
        if(curr == prev)
        {
            tail = NULL;
        }

        // >=2 node linked list
        if(tail == curr)
        {
            tail = prev;
        }
        curr -> next = NULL;

        delete curr;
    }
}

int main()
{
    Node* tail = NULL;

    // insertNode(tail, 111,3);
    // print(tail);

    // insertNode(tail, 3,5);
    // print(tail);
    // insertNode(tail, 5,7);
    // print(tail);
    // insertNode(tail, 7,89);
    // print(tail);

    deleteNode(tail, 89);
    print(tail);
}