#include<iostream>
using namespace std;

int fact(int n)
{
    int fac = 1;
    if(n == 0)
    {
        return 1;
    }
    else
    {
        fac = n * fact(n-1);
    }
    return fac;
}
int main()
{
    int n;
    cout << "Enter any number : " << " ";
    cin >> n;

    int result = fact(n);
    cout << "The factorial is : " << result << " ";
}