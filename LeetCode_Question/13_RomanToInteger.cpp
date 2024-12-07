#include<bits/stdc++.h>
using namespace std;

int romanToInteger(string str)
{

    unordered_map<char, int> m;
    
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

    int ans = 0;

    for(int i = 0; i < str.size(); i++)
    {
        if(m[str[i]] >= m[str[i+1]])
        {
            ans += m[str[i]];
        }
        else{
            ans -= m[str[i]];
        }
    }
    return ans;

}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int ans = romanToInteger(str);
    cout << "Integer value of the roman number is: " << ans << endl;
    return 0;
}