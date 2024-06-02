#include<iostream>
using namespace std;

int main()
{
    int number;
    cout<<"Enter any number: "<<endl;
    cin>>number;

    if(number>0) cout<<"The given number "<<number<<" is positive number"<<endl;
    else if(number<0) cout<<"The given number "<<number<<" is negative number"<<endl;
    if(number==0) cout<<"The given number "<<number<<" is equal to zero"<<endl;

}