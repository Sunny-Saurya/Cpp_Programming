#include<iostream>
using namespace std;

int PrintArray(int array[] , int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<< array[i] << " ";
    }
}
int main()
{
    int array[5] = {1,2,3,4,5};
    cout<< array[4] << endl;

    int first[10] = {2,7};
    PrintArray(first , 10);
    cout<<endl;

    int second[15] = {0};  // it gives 0 in all the indexes.
    PrintArray(second , 15);
    cout<<endl;

    int third[15] = {1}; // it gives only 1 in third[0] and rest all is 0.

    PrintArray(third , 15);
    cout<<endl;
    
    int fourth[15] = {}; // it gives only 1 in third[0] and rest all is 0.

    PrintArray(fourth , 15);
}