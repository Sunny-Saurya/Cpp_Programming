// c++ control structure
// 1. sequence structure
// 2. selection structure ==> dicision making / check condition as per the question.
// 3. loop structure ==> entry ==> condition ==> loop ==> increment/decrement.

// SELECTION STRUCTURE : SWITCH CASE 

#include<iostream>
using namespace std;

int main()
{
    int age;
    cout<<"enter yuor age"<<endl;
    cin>>age;

    switch(age)
    {
    case 18:
        cout<<"you are 18";
        break;
    case 22:
        cout<<"you are 22"<<endl;
        break;
    case 5:
        cout<<"you are 5"<<endl;
        break;
    default:
        cout<<"no speial cases"<<endl;
        break;

    }
}
