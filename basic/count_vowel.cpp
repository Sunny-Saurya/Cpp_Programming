// Write a Program to Count the Number of Vowels 

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int count = 0;
    string str = "ohhmygoodness";
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' )
        {
            count++;
        }
    }
    cout<<"The total number of vowel in given string is = "<<count;
}