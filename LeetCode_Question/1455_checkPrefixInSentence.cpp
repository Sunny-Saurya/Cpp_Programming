#include<bits/stdc++.h>
using namespace std;

int isPrefixOfWord(string word, string pref)
{
    istringstream stream(word);
    string sentence;

    int index = 1;

    while(stream >> word)
    {
        if(word.find(pref) == 0)
        {
            return index;
        }
        index++;
    }
    return -1;
}

int main()
{
    string word;
    cout << "Enter a sentence: ";
    getline(cin, word);

    string pref;
    cout << "Enter a prefix: ";
    getline(cin, pref);

    int result =  isPrefixOfWord(word, pref);
    cout << "Result: " << result;
    cout << endl;
    cout << endl;

}