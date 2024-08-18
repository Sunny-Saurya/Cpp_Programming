#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& s, int x)
{
    // base case
    if(s.empty()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, x);

    // push the top element back after inserting at bottom
    s.push(temp);
}

void reverseStack(stack<int>& s)
{
    // base case
    if (s.empty()){
        return;
    }
    
    int temp = s.top();
    s.pop();

    // recursive
    reverseStack(s);

    // insert temp element at the bottom
    insertAtBottom(s, temp);
}

void printing(stack<int> s)
{
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;

    // Populate the stack with elements
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++) {
        s.push(arr[i]);
    }

    // Reverse the stack
    reverseStack(s);

    // Print the reversed stack
    printing(s);

    return 0;
}
