#include<iostream>
using namespace std;

int main()
{
    char ch;
    cout<<"Enter any character: "<<endl;
    cin>>ch;

    if(ch>'a' && ch<'z')
    {
        cout<<"The given character "<< ch <<" is lowercase."<<endl;
    }
    else if(ch>'A' && ch<'Z')
    {
        cout<<"The given character "<< ch <<" is uppercase."<<endl;
    }
    else{
        cout<<"The given character is number and that is "<<ch;
    }
}