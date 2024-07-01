// power of two

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter any numebr:"<<endl;
    cin>>n;

    int ans;

    for(int i = 0; i<31; i++)
    {
        int ans = pow(2,i);
        
    }
    if(ans == n)
    {
        cout<<"True"<<endl;
    }
}