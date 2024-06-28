#include<iostream>
using namespace std;

int main()
{
    char name[20]; // Use char instead of int for storing strings
    cout << "Enter your name : ";
    cin >> name;   // nut this do not print after the space, \t, \n, or enter

    cout << "Your name is : " << name << endl;

    return 0;
}