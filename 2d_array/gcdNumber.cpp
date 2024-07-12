#include<iostream>
using namespace std;

// using euclid's algorithms


int gcd(int n1, int n2)
{
    if(n1 == 0)
    return n2;

    if(n2 == 0)
    return n1;

    while(n1 != n2)
    {
        if(n1 > n2)
        {
            n1 = n1 - n2;
        }
        else{
            n2 = n2 - n1;
        }
    }
    return n1;
}
int main()
{
    int n1;
    cout << "Enter first number : " << " ";
    cin >> n1;
    
    int n2;
    cout << "Enter second number : " << " ";
    cin >> n2;
    
    int ans = gcd(n1,n2);
    cout << "GCD of " << n1 << " and " << n2 << " is " << ans << " ";
}