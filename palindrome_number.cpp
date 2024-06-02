#include<iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int temp = num;  // Initialize temp after taking input
    int rev = 0;

    while(num!= 0)
    {
        int rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
    if(temp == rev)
    {
        cout << "Yes, this number is a palindrome number" << endl;
    }
    else
    {
        cout << "No, this number is not a palindrome number" << endl;
    }
    return 0;
}