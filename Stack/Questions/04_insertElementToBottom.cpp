#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int x)
{
    // base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();

    // recursive call
    solve(s, x);

    s.push(top);
}

void pushAtBottom(stack<int>& s, int x)
{
    solve(s, x);
}

void print(stack<int> s)
{
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[100];

    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    stack<int> s;

    for(int i = 0; i < size; i++)
    {
        int num = arr[i];
        s.push(num);
    }

    int x;
    cout << "Enter element to insert: ";
    cin >> x;

    pushAtBottom(s, x); // No need to assign to any variable
    print(s);

    return 0;
}
