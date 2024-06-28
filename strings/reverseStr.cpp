// Reverse the string 
// Given a string, return a new string with the reversed order of characters.   
// Example: "hello" -> "lohel"
// function reverseString(str) {
//     let newStr = str.split('').reverse().join('');
//     return newStr;
//     }

#include<iostream>
using namespace std;

int reverseStr(char name[], int n)
{
    int s = 0;
    int e = n-1;

    while (s < e)
    {
        swap(name[s], name[e]);
        s++;
        e--;
    }
    
}

int getLenght(char name[]) // not need of lenght
{
    int sum = 0;

    for(int i = 0; name[i] != '\0'; i++)
    {
        sum++;
    }
    return sum;
}

int main()
{
    char name[20];
    cout<<"Enter your name: ";
    cin>>name;

    int length = getLenght(name);
    int reverse = reverseStr(name,length);
    cout << "Reverse array is : " << name << " ";
}