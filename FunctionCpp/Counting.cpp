#include<iostream>
using namespace std;

int Counting(int n)
{
    for(int i = 1; i<=n; i++)
    {
        cout<< i << " ";
    }
}
int main()
{
    int n;
    cout<<"Enter last number till you want the counting: ";
    cin>>n;

    Counting(n);
}