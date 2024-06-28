#include<iostream>
using namespace std;

int getLenght(char name[]) // not need of lenght
{
    int sum = 0;

    for(int i = 0; name[i] != '\0'; i++)
    {
        sum++;
    }
    return sum;
}
int main()
{
    char name[20];
    cout<<"Enter your name: ";
    cin>>name;

    int length = getLenght(name);
    cout << "The lenght of the string is : " << length << " ";
}