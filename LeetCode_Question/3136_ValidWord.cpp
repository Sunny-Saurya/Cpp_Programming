#include<bits/stdc++.h>
using namespace std;

bool validWord(string str)
{
    bool hasVowels = false;
    bool hasConsonants = false;

    if(str.length() < 3) return false;

    for(char c : str)
    {
        if(!isalnum(c)) return false;

        // checking vowels

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                hasVowels = true;
        }

        // checking consonants

        if(isalpha(c)){
            hasConsonants = true;
        }

        return hasVowels && hasConsonants;
    }
};

int main()
{
    string str;
    cout << "Enter your string here: ";
    getline(cin, str);

    if(validWord(str)){
        cout << "Valid word !!" << endl;
    }
    else{
        cout << "Not valid word !!" << endl;
    }
}