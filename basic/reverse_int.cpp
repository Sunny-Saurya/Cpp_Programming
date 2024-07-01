#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter any number to reverse: "<<endl;
    cin>>n;

    int rev = 0;

    while (n != 0)  
    {
        int rem = n % 10;
        rev = rev * 10 + rem;
        n = n/10;
    }
    if(rev > (pow(2,31) )|| rev < (pow(2,-31)))
    {
        cout<<0<<endl;
    }
    else{
        cout<<"Reverse is : "<<rev;
    }
    
}