#include<iostream>
using namespace std;

int main(){
    
    // what is a pointer ?==> pointer is a datatype which holds the address of other data types.
    
    int a = 3;
    int *b = &a;
    cout<<b<<endl; // b is a pointer which store the address of a.

    // & ===> (Address of) operator
    cout<<"The address of a is : "<<&a<<endl;
    cout<<"The address of a is : "<<b<<endl;

    // * ===> (value at) Dereference operator
    cout<<"The value at address of b is : "<<*b<<endl;

    // Pointer to Pointer
    int ** c = &b;
    cout<<"The address of b is : "<<&b<<endl;
    cout<<"The address of b is : "<<c<<endl;
    cout<<"The value at address value_at(value_at(c)) is "<<*c<<endl;
    cout<<"The value at address value_at(value_at(c)) is "<<**c<<endl;


    return 0;
}