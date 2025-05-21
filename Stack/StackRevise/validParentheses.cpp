#include <bits/stdc++.h>
using namespace std;

bool matches(char top, char ch)
{

    if ((top == '(' && ch == ')') ||
        (top == '{' && ch == '}') ||
        (top == '[' && ch == ']'))
    {
        return true;
    }
    return false;
}

bool isValidParentheses(string str)
{

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];

        // if open bracker, push into the stack
        // if close bracket then compare and pop

        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }

        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if (matches(top, ch))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    string str;
    cout << "Write the Expression : ";
    cin >> str;

    if (isValidParentheses(str))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
}