#include<iostream>
using namespace std;

  
int& func(int a) // bad practice
{
    int num = a;
    int& ans = num;
    return ans;
}

// pass by reference
void update(int &n)
{
    n++;  // it does not create coppy
}
int main()
{
    /*
    int i = 5;
    int &j = i;

    cout << i << endl; // 5
    i++;
    cout << i << endl; //6 
    j++;
    cout << i << endl; // 7
    cout << j << endl;// 7

    */

   int n = 5;
   cout << "Before : " << n << endl;

   update(n);

   cout << "After " << n << endl;

   func(n);
}