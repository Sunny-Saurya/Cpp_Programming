#include<iostream>
using namespace std;

int main()
{
    int num = 5;
    cout << num << endl;

    // address of operator - &

    cout << "address of num is " << &num << endl;

    int *ptr = &num;
    cout << "value is : " << *ptr << endl; // this print the value, that present in the address of ptr.

    cout << "address of ptr is : " << ptr << " "; // this print the address of ptr

    cout << endl;

    double d = 4.2;
    double *p2 = &d;

    cout << "value is : " << *p2 << endl; // this print the value, that present in the address of ptr.

    cout << "address of ptr is : " << p2 << endl; // this print the address of ptr


    cout << "size of integer is " << sizeof(num) << endl;

    cout << "size of  pointer is " << sizeof(ptr) << endl;

    cout << "size of  pointer is " << sizeof(p2) << endl;


}