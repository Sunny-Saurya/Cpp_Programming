// input = 412
// output = four one two

#include<iostream>
using namespace std;

void sayDigits(int n, string numbers[])
{
    // base case 

    if(n == 0)
        return ;

    // processing 

    int digit = n % 10;
    n = n / 10;

    // recurssive function

    sayDigits(n, numbers);
    cout << numbers[digit] << " ";

    

}
int main()
{
    int n;
    cout << "Enter any number :  " << endl;
    cin >> n;

    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigits(n,numbers);
}