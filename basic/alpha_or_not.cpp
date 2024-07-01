//Write a Program to Print Check Whether a Character is an Alphabet or Not

/* #include<iostream>
using namespace std;

int main()
{
    char ch;
    cout<<"Enter a character: ";
    cin>>ch;

    if(ch >= 'a' && ch<='z' || ch >= 'A' && ch<='Z')
    {
        cout<<ch<<" is an alphabet";
    }
    else cout<<ch<<" is not an alphabet";
} */

// -----------------by using built-in function-------------------

#include <cctype> 
#include <iostream> 
using namespace std; 

int main() 
{ 
	char ch; 
    cout<<"Enter a character: ";
    cin>>ch;

	if (isalpha(ch)) { 
		cout << ch << " is an alphabet." << endl; 
	} 
	else { 
		cout << ch << " is not an alphabet." << endl; 
	} 

	return 0; 
}

