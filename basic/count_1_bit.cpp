// Count the number of 1 bit from an unsigned integer

#include<iostream>
using namespace std;

int main()
{
    unsigned int n;
    cout<<"Enter any number to know 1 bit: "<<endl;
    cin>>n;

    int count = 0;

    while(n!=0)
    {
        int rem = n % 10;
        if(rem == 1)
        {
            count++;
        }
        n = n/10;
    }
    cout<<count<<endl;

}