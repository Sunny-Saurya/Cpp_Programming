#include<iostream>
using namespace std;

int main()
{
    int array[5] = {1,2,3,4,5};
    cout<< array[4] << endl;

    int first[10] = {2,7};
    for(int i = 0; i<10; i++)
    {
        cout<< first[i] << " ";
    }

    cout << endl;

    int second[15] = {0};  // it gives 0 in all the indexes.
    for(int i = 0; i<15; i++)
    {
        cout<< second[i] << " ";
    }

    cout << endl;

    int third[15] = {1}; // it gives only 1 in third[0] and rest all is 0.

    for(int i = 0; i<15; i++)
    {
        cout<< third[i] << " ";
    }

    cout << endl;

    int fourth[15] = {}; // it gives only 1 in third[0] and rest all is 0.

    for(int i = 0; i<15; i++)
    {
        cout<< fourth[i] << " ";
    }
}