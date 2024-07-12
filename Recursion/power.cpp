#include<iostream>
#include<math.h>
using namespace std;

int power(int base, int expo)
{
    // base condition
    if(base == 0)
    {
        return 0;
    }
    if(expo == 0)
    {
        return 1;
    }
    // recusive function
    else
    {
        return base * power(base, expo - 1);
    }

}

int main()
{
    int base;
    cout << "Enter base : " << " ";
    cin >> base;

    int expo;
    cout << "Enter expo : " << " ";
    cin >> expo;

    int result = power(base, expo);
    cout << "The power is : " << result << " ";
}