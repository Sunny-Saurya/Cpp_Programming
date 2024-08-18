// Reverse the string using stack

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string name = "Sunny";
    stack<char> s;

    for(int i =0; i < name.size(); i++)
    {
        s.push(name[i]);
    }

    string ans = " ";

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }
    cout << "Answer is : " << ans << endl;
}