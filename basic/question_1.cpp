// subtract the product and the sum the digit of an integer.

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter any number: "<<endl;
    cin>>n;

    int sum = 0;
    int pro = 1;

     while(n != 0)
    {
        int rem = n % 10;
        sum = sum + rem;
        pro = pro * rem;
        n = n/10;
    }
    cout<<"The sum = "<<sum<<endl;
    cout<<"The product = "<<pro<<endl;

    cout<<"The difference between the product and sum is = "<<pro - sum<<endl;
}