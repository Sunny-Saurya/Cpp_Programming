#include<bits/stdc++.h>
using namespace std;

class Heap
{
    public:
    int arr[100];
    int size;

    // constructor

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // inserting element into heap using an array

    void insert(int val)
    {
        size = size + 1;
        int index = size;

        arr[index] = val;

        while(index > 1)
        {
            int parent = index / 2;
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return ;
        }
    }


    void print(){
        cout << "Min Heap : ";
        for(int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(25);
    h.print();
    return 0;

}