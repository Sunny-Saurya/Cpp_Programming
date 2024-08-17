#include<iostream>
#include<stack>
using namespace std;

int main()
{

    // creation of stack
    stack<int> s;

    // push - for passing data
    s.push(10);
    s.push(20);
    s.push(30);

    // pop - for deletion
    s.pop();

    cout << "Printing top Element : " << s.top() << endl;

    // is empty

    if(s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "size of stack is : " << s.size() << endl;
}