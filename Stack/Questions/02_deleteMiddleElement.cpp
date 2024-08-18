#include<iostream>
#include<stack>
using namespace std;

// Function to solve the deletion of the middle element

void solve(stack<int>& s, int count, int size) {
    if(count == size/2) {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, count + 1, size);
    s.push(temp);  // Push the element back after the recursive call
}

// Function to delete the middle element
void deleteMiddle(stack<int>& s, int n) {
    int count = 0;
    solve(s, count, n);
}

// Function to print the stack elements
void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    int m;
    cout << "Enter size of Stack : " << " ";
    cin >> m;

    int arr[m];

    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    
    int n = sizeof(arr)/sizeof(arr[0]);

    // Pushing elements into the stack
    for(int i = 0; i < n; i++) {
        s.push(arr[i]);
    }

    // Deleting the middle element
    deleteMiddle(s, n);

    // Printing the updated stack
    cout << "Updated stack after deleting the middle element: ";
    printStack(s);

    return 0;
}
