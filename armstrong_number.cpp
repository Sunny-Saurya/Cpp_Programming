#include<iostream>
using namespace std;

int main()
{
    int num, originalNum, result = 0;
    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;  // Store the original number

    while(num!= 0)
    {
        int rem = num % 10;
        result += rem * rem * rem;  // Calculate the sum of cubes of digits
        num = num / 10;
    }
    if(originalNum == result)
        cout << "Yes, this is an Armstrong number" << endl;
    else
        cout << "No, this is not an Armstrong number" << endl;
    return 0;
}