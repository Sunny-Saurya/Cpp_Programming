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
        cout << "Memery is free for node with data : " << value << endl;

    }
};

int main()
{
    Node* node1 = new Node(12);
    cout << node1 -> data << " ";
}