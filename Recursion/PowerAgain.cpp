#include<iostream>
using namespace std;

int power(int base, int expo)
{
    if(base == 0)
    {
        return 0;
    }
    if(expo == 0)
    {
        return 1;
    }

    int ans = power( base, expo/2);

    if(expo % 2 == 0)
    {
        // if b is even
        return ans * ans;
    }
    else{
        // if b is odd
        return base * ans * ans;
    }
}

int main()
{
    int base, expo;
    cout << "Enter base : " << " ";
    cin >> base;

    cout << "Enter expo : " << " ";
    cin >> expo;

    cout << "The power is : " << power(base, expo) << " ";
}