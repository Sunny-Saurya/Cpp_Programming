#include <bits/stdc++.h>
using namespace std;

bool redundantBrackets(string &s)
{

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }

        else
        {
            // ch is closing and lowercase .. which can be ignore 

            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();

                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                {
                    return true;
                }

                st.pop();
            }
        }
    }

    return false;
}

int main()
{
    string str;

    cout << "Enter Expression: ";
    cin >> str;

    if (redundantBrackets(str))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}