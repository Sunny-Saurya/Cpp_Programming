#include<iostream>
using namespace std;

int sum (int a, int b){
    int c = a + b;
    return c;
}
// This will not swap the value of a and b.
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// CALL BY REFERENCE USING C++ REFERENCE VARIALABLE.

// void swapPointer(int*a, int* b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

 int main(){
//     int x = 4 , y = 5;

//     //cout<<"The sum of 4 and 5"<<sum(4,5);
//     cout<<"The value of x is"<<x<<"And the value of y is "<<y<<endl;

//     swapPointer (&x,&y); // Thsi will swap the value using pointer reference.
//     // swap(x, y); // This will not swap the value of a and b.
//     cout<<"The value of x is"<<x<<"and the vlaue of  y is"<<y<<endl;

// ANOTHER WAY TO USE CALL BY REFERENCE.

void swapReferenceVar(int a, int b)
{
    int temp = a;
    a = b
    b = temp;
}

int main(){
    int x = 4 , y = 5;

    //cout<<"The sum of 4 and 5"<<sum(4,5);
    cout<<"The value of x is"<<x<<"And the value of y is "<<y<<endl;

    swapReferenceVar(x,y); // Thsi will swap the value using pointer reference.
    // swap(x, y); // This will not swap the value of a and b.
    cout<<"The value of x is"<<x<<"and the vlaue of  y is"<<y<<endl;
    return 0;

}