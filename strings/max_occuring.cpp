// test ===> t = 2, e = 1, s = 1 ===> ans ==> t (max)

#include<iostream>
using namespace std;

char getMaxOcc(string s){
    
    int arr[26] = {0};

    // create an array of count of characters;

    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;

        if(ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else{
            number  = ch - 'A';
        }
        arr[number]++;
    }

    int maxi = -1;
    int ans = 0;

    for(int i = 0; i<26; i++)
    {
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }

    char finalAns =  'a' + ans;
    return finalAns;
}


int main()
{
    string s;
    cout <<"Enter string : " << " ";
    cin >> s;
    
    cout << "Max occurring character is : " << getMaxOcc(s) << " ";
}