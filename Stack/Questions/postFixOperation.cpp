// You are using GCC
#include<bits/stdc++.h>
using namespace std;

int postfixExp(string str)
{
    stack<int> st;
    
    for(int i = 0; i < str.size(); i++)
    {
        if(isdigit(str[i]))
        {
            st.push(str[i] - '0');
        }
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            
            switch(str[i])
            {
                case '+':
                st.push(val1 + val2);
                break;
                case '-':
                st.push(val2 - val1);
                break;
                case '*':
                st.push(val1 * val2);
                break;
                case '/':
                st.push(val2 / val1);
                break;
                
                
            }
        }
    }
    return st.top();
}

int main()
{
    string str;
    cout << "Enter your string here : " ;
    cin >> str;
  
  cout << "Postfix expression evaluation : " << postfixExp(str) << endl;
  return 0;
}