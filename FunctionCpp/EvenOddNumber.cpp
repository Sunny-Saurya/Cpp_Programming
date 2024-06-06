#include<iostream>
using namespace std;

int EvenOdd(int a)
{
    if(a % 2 == 0)
    {
        cout<< a << " is even number"<<endl;
    }
    else
    {
        cout<< a << " is odd number"<<endl;
    }
}
int main()
{
    int number;
    cout<<"Enter any number to check even and odd : "<<endl;
    cin>>number;

    EvenOdd(number);
}