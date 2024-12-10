#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomeNote, string magazine)
{
    unordered_map<char, int> mpp;

    for(char c : magazine)
    {
        mpp[c]++;
    }

    for(char ch : ransomeNote)
    {
        if(mpp[ch] > 0){
            mpp[ch]--;
        }
        else{
            return false;
        }
    }

    return true;
}

int main()
{
    string ransomeNote;
    cout << "String 1: ";
    cin >> ransomeNote;

    string magazine;
    cout << "String 2: ";
    cin >> magazine;
    
    bool result = canConstruct(ransomeNote, magazine);

    if(!result)
    {
        cout <<"Can't construct !!";
    }
    else{
        cout << "Can construct !!";
    }

}