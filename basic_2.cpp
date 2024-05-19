#include<iostream>
using namespace std;

int c = 45;  // global variable

int main()
{
    //*************BUILT IN DATA TYPE***************

    // int a,b,c; //local variable
    // cout<<"Enter the value of a "<<endl;
    // cin>>a;

    // cout<<"Enter the value of b "<<endl;
    // cin>>b;

    // c = a + b;
    // cout<<"The  sum is "<<c<<endl; // give output as local
    // cout<<"The  sum is "<<c<<endl; // give output as local

    // cout<<"The  sum is "<<::c<<endl; //when we give scope resolution(::) then this gives output as global variable.

    //**************FLOAT,DOUBLE AND LONG DOUBLE LITERALS****************

    // float d = 34.4f;  // (f/F) 34.4 is long double not a float but when we write 34.4 as (34.4f) then it act as float.
     
    // long double e = 34.4l; // l/L for long double.

    // cout<<"The size of 34.4 is "<<sizeof(34.4)<<endl;
    // cout<<"The size of 34.4f is "<<sizeof(34.4f)<<endl;
    // cout<<"The size of 34.4F is "<<sizeof(34.4F)<<endl;
    // cout<<"The size of 34.4l is "<<sizeof(34.4l)<<endl;
    // cout<<"The size of 34.4L is "<<sizeof(34.4L)<<endl;
    
    // cout<<"The value of d is"<<d<<endl<<"The value of e is"<<e;

    // ********************REFERENCE VARIABLE*************************

    // Rohan ---> Monty ---> Rohu ---> Dangerous coder

    // float x = 455;
    // float & y = x; //(&) ampercent variables used for reference variable
    // cout<<x<<endl;
    // cout<<y<<endl;

    // ******************TYPECASTING***********************

    // int a = 45;
    // float b = 45.54;

    // cout<<"The value of a is ==> "<<(float)a<<endl;
    // cout<<"The value of b is ==> "<<(int)b<<endl;

    // cout<<"The value of b is "<<(int)b<<endl;
    // cout<<"The value of b is "<<int(b)<<endl;

    // cout<<"The expression is "<< a + b<<endl;
    // cout<<"The expression is"<< a + int(b)<<endl;
    // cout<<"The expression is "<<a + (int)(b)<<endl;



    return 0;

}