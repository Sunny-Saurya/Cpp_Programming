// #include<iostream>
// using namespace std;

// struct employee
// {
//     /* data */
//     int eId;
//     char favChar;
//     float salary;
// };

// union money //it shares the memory.
// {
//     /* data */
//     int rice;
//     char car;
//     float pounds;
// };


// int main(){

//     enum meal{breakfast,lunch,dinner};
//     cout<<breakfast<<endl;
//     cout<<lunch<<endl;
//     cout<<dinner<<endl;

    // union money m1;
    // m1.rice = 40;
    // m1.car = 'c';
    // cout<<m1.car;

    // struct employee harry;
    // harry.eId = 1;
    // harry.favChar  = 'c';
    // harry.salary = 120000000;
    // cout<<"The value is"<<harry.eId<<endl;
    // cout<<"the value is"<<harry.favChar<<endl;
    // cout<<"The value is"<<harry.salary<<endl;
    // return 0;
// }

// sum of 5 number by using name.

// #include<iostream>
// using namespace std;

// int main(){
//     int a[5],sum = 0;
//     cout<<"Enter any five digit";
//     for(int i = 0; i<5; i++)
//     cin>>a[i];
//     for(int i = 0;i<5; i++)
//     {
//         sum = sum + a[i];
//     }
//     cout<<"sum of the given number is ==> "<<sum;
//     return 0;
// }

// Inserting a number in an array.

#include<iostream>
using namespace std;

int main(){
    int a[100], i = 0;  
    char choice = 'y';
    do
    {
        cout<<"Enter the first element"<<i+1<<endl;
        cin>>a[i];
        i++;
    cout<<"Do you want to enter again(press y)";
    cin>>choice;
    }
    while(choice =='y' || choice == 'Y');
    for(int k = 0;k<i;k++)
    {
        cout<<a[k];
    }
}