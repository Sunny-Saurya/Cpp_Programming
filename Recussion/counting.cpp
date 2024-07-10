#include<iostream>
using namespace std;

void couting(int n)
{
    if(n == 0)
    {
        return;
    }
    cout << n << " ";
    couting(n-1);
}

int main()
{
    int n;
    cout << "Enter any number : " << " ";
    cin >> n;

    couting(n);
    
}