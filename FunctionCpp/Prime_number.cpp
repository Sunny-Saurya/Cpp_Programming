#include<iostream>
using namespace std;

int isPrime(int n)
{
    int count = 0;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            count++;
        }
    }
    if(count == 2)
    {
        cout<< n << ",is prime number";
    }
    else 
    {
        cout<< n << ",is not prime number";
    }
}
int main()
{
    int num;
    cout<<"Enter any number to check prime number: "<<endl;
    cin>>num;

    isPrime(num);
}
