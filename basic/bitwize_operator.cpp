#include<iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 5;

    cout<<"a&b=> "<< (a&b) <<endl;
    cout<<"a&b=> "<< (a|b)<<endl;
    cout<<"~a=> "<< (~a)<<endl;
    cout<<"~b=> "<< (~b)<<endl;
    cout<<"a^b => "<< (a^b)<<endl;
    cout<<"b^a => "<< (b^a)<<endl;
}