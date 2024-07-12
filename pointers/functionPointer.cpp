#include<iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl; // value
    cout << p << endl; // address 
}

void update(int *p)
{
    // p = p + 1;
    // cout << "after " << p << endl;

    *p = *p + 1;
    // cout << "after update : " << *p << endl;
}

int getSum(int arr[], int n)
{
    int sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int value = 5;
    int *p = &value;

    // print(p);

    // cout << "before " << p << endl;
    cout << "before " << *p << endl;
    update(p);
    // cout << "after " << p << endl;
    cout << "after value " << *p << endl;


    int arr[6]  = {1,2,3,4,5,5};
    cout << "Sum is " << getSum(arr,6) << endl; // sum ==> 20

    cout << "Sum is " << getSum(arr + 3,3) << endl; // passing some parts of an array to the function from index 3 ---> sum = 14 

char s[]= "hello";
char *r = s;
cout << s[0] << " " << r[0];
    return 0;
}