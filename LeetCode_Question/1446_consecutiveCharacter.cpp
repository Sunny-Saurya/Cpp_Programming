#include<bits/stdc++.h>
using namespace std;

int maxConsecutive(string s)
{
    int maxi = 1;
    int count = 1;

    for(int i = 1; i < s.size(); i++){
        if(s[i-1] == s[i]){
            count++;
        }
        else{
            count = 1;
        }
        maxi = max(maxi, count);
    }

    return maxi;
}

int main()
{
    string s;
    cin >> s;
    
    cout << " Maximum consecutive characters: " << maxConsecutive(s) << endl;
}