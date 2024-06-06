#include<iostream>
using namespace std;

int power(int a, int b)
{
    int ans = 1;
    for(int i = 1; i <= b; i++)
    {
        ans = ans * a;
    }
    return ans;
}
int main()
{
    int a , b;
    cout<<"Enter base number: "<<endl;
    cin>>a;

    cout<<"Enter expo number: "<<endl;
    cin>>b;

    int result = power(a,b);
    cout<<"The answer is : "<<result<<endl;
}