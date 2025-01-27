#include<bits/stdc++.h>
using namespace std;

string addString(string s1, string s2)
{
    string result = " ";
    int n1 = s1.length() - 1;
    int n2 = s2.length() - 1;
    int carry = 0;

    while(n1 >= 0 || n2 >= 0 || carry > 0)
    {
        int digit1 = (n1 >= 0)? s1[n1] - '0' : 0;
        int digit2 = (n2 >= 0)? s2[n2] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result +=  (sum % 10) + '0';
        n1--;
        n2--;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s1;
    cout << " Enter first string: ";
    cin >> s1;
    
    string s2;
    cout << " Enter second string: ";
    cin >> s2;

    cout << " Sum of two strings: " << addString(s1, s2);
    return 0;
}