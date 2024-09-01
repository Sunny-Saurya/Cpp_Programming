#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, int d, vector<int>&arr)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    arr.push_back(d);
}

Node* sortList(vector<int>&arr)
{
    sort(arr.begin(), arr.end());
    Node dummy(0);
    Node* sortedList = &dummy;

    for (int i = 0; i < arr.size(); ++i) {
        sortedList->next = new Node(arr[i]);
        sortedList = sortedList->next;
    }

    return dummy.next;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *tail = node1;
    Node *head = node1;
    vector<int> arr;

    insertAtTail(tail, 9, arr);
    insertAtTail(tail, 3, arr);
    insertAtTail(tail, 4, arr);
    insertAtTail(tail, 0, arr);
    insertAtTail(tail, 11, arr);
    insertAtTail(tail, 5, arr);

    cout << "Unsorted List: ";
    print(head);


    Node* sortedHead = sortList(arr);

    
    cout << "Sorted List: ";
    print(sortedHead);

    return 0;
}
