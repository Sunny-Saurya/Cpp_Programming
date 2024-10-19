#include<bits/stdc++.h>
using namespace std;
#define SIZE 3

int myStack[SIZE], top = -1;

void push(int value)
{
    if(top == SIZE - 1){
        cout << "Stack Overflow!" << endl;
    }
    else{
        top++;
        myStack[top] = value;
    }
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow!" << endl;
    }
    else{
        cout << "The deleted element from the stack is " << myStack[top] << endl;
        top--;
    }
}

void display()
{
    if(top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack elements are: ";
        for(int i = top; i >= 0; i--)
        {
            cout << myStack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice, value;

    while(true)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Wrong selection!" << endl;
            break;
        }
    }

    return 0;
}
