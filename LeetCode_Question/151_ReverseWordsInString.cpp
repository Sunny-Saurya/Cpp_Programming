#include<bits/stdc++.h>
using namespace std;

string reverseString(string word)
{
    istringstream ss(word);
    string str;
    vector<string> ans;

    while(ss >> word)
    {
        ans.push_back(word);
    }

    string res;

    for(int i = ans.size() -1; i >= 0; i--)
    {
        res += ans[i];

        if(i != 0) res += " ";
    }

    return res;


}

int main()
{
    string word;
    cout << "Enter the string : ";
    getline(cin, word);

    string result = reverseString(word);

    cout << "Reversed string is : " << result;
    cout << endl;
}