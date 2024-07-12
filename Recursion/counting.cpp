#include<iostream>
using namespace std;

void couting(int n)
{
    // base case
    if(n == 0)
    {
        return;
    }

    //recussive function
    cout << n << " ";
    couting(n-1);

    // series wise
    // cout << n << " ";
    // couting(n-1);
}

int main()
{
    int n;
    cout << "Enter any number : " << " ";
    cin >> n;

    couting(n);
    
}