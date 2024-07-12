// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;

int Prime(int n)
{

for(int i = 2; i <= n; i++)
{
    if(n <= 1)
    {
        return false;
    }
    if(n % i == 0)
    {
        return false;
    }
    else{
        return true;
    }
}
}

int isPrime(int n)
{
    int count = 0;
    for(int i = 2; i < n; i++)
    {
        if(Prime(i))
        {
            count++;
        }
    }
    return count;
}

int  main()
{
    int n;
    cout << "Enter number : " << " ";
    cin >> n;
    
    Prime(n);
    int total = isPrime(n);
    cout << "There are  "<<  total <<  " number less then  " <<  n << " ";
   
}