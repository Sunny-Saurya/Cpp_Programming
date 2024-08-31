#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int>& q) 
{
    stack<int> s;
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    while (!s.empty()) {
        int element = s.top();
        q.push(element);
        s.pop();
    }
}

int main()
{
    queue<int> q;

    int arr[5] = {1, 2, 2, 3, 4};

    for (int i = 0; i < 5; i++) {
        q.push(arr[i]);
    }

    cout << "Original Queue: ";

    queue<int> temp = q;  // Use a temporary queue to print the original queue
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    reverseQueue(q);  // Reverse the queue

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
