#include<iostream>
using namespace std;

int main()
{
    int starting_point;
    cout<<"Enter starting number "<<endl;
    cin>>starting_point;

    int ending_point;
    cout<<"Enter ending number "<<endl;
    cin>>ending_point;

    while(starting_point<=ending_point)
    {
        cout<<starting_point;
        starting_point++;
        cout<<"\n";
    }
}