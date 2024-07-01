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

    int sum = 0;

    while(starting_point<=ending_point)
    {
        cout<<starting_point<<" ";
        sum = sum + starting_point;
        starting_point++;
    }
    cout<<"\n";
    cout<<"The total of given number is "<<sum<<endl;
}