#include <bits/stdc++.h>
using namespace std;

string sortSentence(string &str){
    vector<string> words(10);
    istringstream ss(str);

    string word;
    int count = 0;

    while(ss >> word){
        int index = word.back() - '0';
        words[index] = word.substr(0, word.size() -1);
        count++;
    }
    string result;
    for(int i = 1; i <= count; i++){
        result += words[i] + " ";
    }

        result.pop_back();  
    

    return result;
}

int main()
{
    // String Input
    string str;
    cout << "Enter Your String: ";
    getline(cin, str);

    cout << "The sorted string: ";
    string sentence = sortSentence(str);
    for(auto i : sentence){
        cout << i ;
    }
    return 0;
}