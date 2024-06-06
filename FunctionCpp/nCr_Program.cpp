#include<iostream>
using namespace std;

int fact(int num)
{
    if(num == 0 || num == 1) return 1;
    else return num * fact(num - 1);
}

int main()
{
    int n, r;
    cout<<"Enter any number : ";
    cin>>n;

    cout<<"Enter any number : ";
    cin>>r;

    //  nCr = n! / r! * (n - r)!

    int result = fact(n) /( fact(r) * fact(n - r));
    cout<<"Anser is : "<< result;

}