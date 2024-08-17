#include<iostream>
using namespace std;

class MyStack {
    // properties
    public:
    int *arr;
    int top;
    int size;

    // behaviour
    MyStack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peak() {
        if(top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value when stack is empty
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    ~MyStack() {
        delete[] arr;
    }
};

int main() {
    MyStack s(5);
    s.push(10);
    s.push(11);
    s.push(6);
    s.push(44);

    cout << s.peak() << endl;

    s.pop();
    cout << s.peak() << endl;

    return 0;
}
