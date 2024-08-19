#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &s, int x)
{
    // base case
    if(s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }

    int n = s.top();
    s.pop();

    // recursive call
    sortedInsert(s, x);
    s.push(n);
}

void sortStack(stack<int> &s)
{
    // base case
    if(s.empty()){
        return;
    }
    
    int num = s.top();
    s.pop();

    // recursive call
    sortStack(s);
    sortedInsert(s, num);
}

void print(stack<int> s) // Pass by value to avoid modifying the original stack
{
    while(!s.empty())
    {
        cout << s.top()<< " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);
    print(s);

    return 0;
}
