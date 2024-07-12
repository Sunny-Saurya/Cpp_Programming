#include<iostream>
using namespace std;

void update(int **ptr2)
{
    // ptr2 = ptr2 + 1; // iss kuch change nhi hoga..

    *ptr2 = *ptr2 + 1;

    // **ptr2 = **ptr2 + 1;  // isse value change ho jaega funciton calll karne ke baad.
    // cout << "printing value inside the function : " << endl;
    // cout << **ptr2 << endl; 
}
int main()
{
    int n = 5;
    int *ptr = &n;
    int **ptr2 = &ptr;

// if you want to print value of n = 5;
    cout << n << endl;
    cout << *ptr << endl;
    cout << **ptr2 << endl;

// if you want to print address of n;

    cout << &n << endl;
    cout << ptr << endl;
    cout << ptr2 << endl; // address of ptr

// value before update 

    cout << "value before update  " << endl;
    cout << n << endl;
    cout << ptr << endl;
    cout << ptr2 << endl; 

    cout << "value after update  " << endl;

    update(ptr2);
    cout << n << endl;
    cout << *ptr << endl;
    cout << **ptr2 << endl; 


}