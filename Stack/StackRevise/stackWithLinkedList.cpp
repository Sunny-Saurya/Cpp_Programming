#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void add(int element) {
        if (top < size - 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack is Overflowed !!" << endl;
        }
    }

    void pop() {
        if (top != -1) {
            top--;
        } else {
            cout << "Stack is Underflowed !!" << endl;
        }
    }

    int peek() {
        if (top != -1) {
            return arr[top];
        } else {
            cout << "Stack is Empty !!" << endl;
            return -1; 
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack st(5);
    st.add(21);
    st.add(43);
    st.add(45);
    st.add(46);
    st.add(67);
    st.add(90);
    // st.pop();
    // st.pop();
    // st.pop();

    cout << "Top Element is : " << st.peek() << endl;

    if (st.isEmpty()) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Stack is Not Empty" << endl;
    }

    return 0;
}
