#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(stack<char>& str, char arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        char ch = arr[i];

        // if opening bracket, push to stack
        if(ch == '(' || ch == '[' || ch == '{')
        {
            str.push(ch);
        }
        // if closing bracket, check the top element and pop
        else
        {
            if(!str.empty())
            {
                char top = str.top();
                if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{'))
                {
                    str.pop();
                }
                else
                {
                    return false; // Mismatch found
                }
            }
            else
            {
                return false; // No matching opening bracket
            }
        }
    }

    // If stack is empty, all opening brackets have been matched
    return str.empty();
}

int main()
{
    stack<char> str;
    int n;
    cout << "Enter size: ";
    cin >> n;

    char arr[n];
    cout << "Enter the parentheses: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if(isValidParenthesis(str, arr, n))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
