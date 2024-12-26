#include <bits/stdc++.h>
using namespace std;

int findValue(string s)
{
    int res = 0, i = 0;
    while (i < s.size())
    {
        if (s[i] < '0' || s[i] > '9') return s.size();
        res = res * 10 + s[i++] - '0';
    }
    return res;
}

int maximumValue(vector<string> &str)
{
    int ans = 0;
    for (auto i : str)
    {
        ans = max(ans, findValue(i));
    }
    return ans;
}

int main()
{
    vector<string> str;
    int n;
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter strings: ";
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str.push_back(s); // Use push_back to add strings to the vector
    }

    cout << "Maximum Value: " << maximumValue(str) << endl; // Print the result
    return 0;
}
