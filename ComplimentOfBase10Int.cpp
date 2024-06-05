// Compliment of base 10 integer

/* #include<iostream>
#include<math.h>

using namespace std;

int convertbinary(int n)
{
    int ans = 0;
    int i = 0;

    while(n != 0)
    {
        int bit = n & 1;
        ans = (bit * (pow(10 , i)) + ans);
        n = n >> 1;
        i++;
    }
    return ans;
}
int convertdecimal(int n)
{
    int ans = 0;
    int i = 0;

    while(n != 0)
    {
        int digit = n % 10;
        if(digit == 1)
        {
            ans = ans + pow(2,i);
        }
        n = n/10;
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter any number: "<<endl;
    cin>>n;

    int binary_rep = convertbinary(n);
    cout<<"Binary Repersentation of given number is : "<<binary_rep<<endl;

    int complement = 0;

    int i = 0;

while(binary_rep!= 0)
{
     int rem = binary_rep % 10;

    if(rem == 0)
    {
        rem = 1;
    }
    else
    {
        rem = 0;
    }
    complement = (rem * pow(10, i)) + complement;

    binary_rep = binary_rep / 10;

    i++;
}
    cout<<"Compliment of binary of given number is : "<<complement<<endl;
    cout<<"The decimal number of compliment binary is : "<<convertdecimal(complement)<<endl;
}

// ****************** only by using bitwise operator *************** */

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter any number: "<<endl;
    cin>>n;

    int m = n;
    int mask = 0;
    int ans;

    if(n == 0)
    {
        cout<<1<<endl;
    }
    else{
        while(m != 0)
        {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        ans = (~n) & mask;
    }
    cout<<"The final output is : "<<ans;
}