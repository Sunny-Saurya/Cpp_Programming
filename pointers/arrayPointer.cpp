#include<iostream>
using namespace std;

int main()
{
    /* int arr[10];
    cout << "The address of the first memeory block is : " << arr << endl;
    cout << "The address of the first memeory block is : " << &arr[0] << endl;
    cout << "The address of the first memeory block is : " << arr << endl;
    cout << "The address of the first memeory block is : " << arr[0] << endl;  // print the garbage value

    cout << "5th : " << *arr << endl;

    int *a = &arr[0];
    cout << "The address of the first memeory block is : " << a << endl; // adress of the first eleement
    cout << "The address of the first memeory block is : " << a << endl; // return garbage value of first element.

    int brr[5] = {2,3,5};

    cout << *brr << endl; // value at 0 index
    cout << *(brr + 1) << endl; // value at 1 index

    cout << *(brr + 1) + 1 << endl; // value at 1 index + 1;

    cout << *(brr) + 5 << endl; // value at index 0 + 5


    cout << brr[2] << endl; // return value at index 2
    cout << *(brr + 2) << endl; // return value at index 2

    /*
    so we get to know the formula that is : 
    arr[i] = *(arr + i);
    or 
    i[arr] = *(i + arr);

    */


  /* int i = 2;
   cout << i[brr] << endl; // return the value at index 2 -- > 5


   int *p = &brr[0];
//    int *p2 = &arr;
   cout << *p << endl;


*/
   /* int temp[10];
    cout << sizeof(temp) << endl;
    cout << sizeof(*temp) << endl;
    cout << sizeof(&temp) << endl;

    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl;
    cout << sizeof(*ptr) << endl;
    cout << sizeof(&ptr) << endl;

*/

   /* int a[20] = {1,2,3,4,5};
    cout << a << endl;
    cout << &a << endl;
    cout << &a[0]  << endl;

    int *p = &a[0];
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;

    */


   int arr[10];

//    arr = arr + 1; // error --> it can't be reassigned.

   int *ptr = &arr[0];
   cout << ptr << endl; // address of 0th index element
   ptr = ptr + 1;

   cout << ptr << endl; // address of 1st index element.

// CHARACTER ARRAY 


    char name[6] = "abcde";
    cout << name << endl; // not return address but the value ==> abcde

    cout << &name << endl;
    cout << &(name) + 1 << endl;

    char *a  = &name[0];

    cout << a << endl; // return the value not the address.

    cout << *a << endl; // return the value of 0th index.

    

    char temp = 'z';
    char *x = &temp;
    cout << x << endl; // return garbage char not addresss;

    return 0;
}