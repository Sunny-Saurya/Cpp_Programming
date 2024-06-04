#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number till you want the series: "<<endl;
    cin>>n;

    int sp = 0;
    int secP = 1;
    cout<<sp<<" "<<secP ;

    for(int i = 1; i<=n; i++)
    {
        int NextNumber =  sp + secP;
        cout<< NextNumber<<" ";
        sp = secP;
        secP = NextNumber;
    }
}