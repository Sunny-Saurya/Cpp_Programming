#include<iostream>
using namespace std;

int main()
{ /*

    int i = 5;

    int *q = &i;
    cout << q << endl;  // address
    cout << *q << endl; // value

    int *p = 0 ;
    p = &i;
  
    cout << p <<endl; // address
    cout << *p << endl; // value

*/


    int num = 5;
    int *p = &num;

    cout << num << endl;

    cout << num++ <<  endl;

    cout << (*p)++ << endl;

    // copying a pointer

    int *q = p;
    cout << p << " - " << q << endl;
    cout << p << " - " << *q << endl;

    // important concept

    int i = 3;
    int *t = &i;

    cout << (*t)++ << endl;
    *t  = *t + 1;
    cout << *t << endl;

    cout << "before :  " << t << endl;
    t = t + 1;
    cout << t << endl;



    return 0;

}