#include<bits/stdc++.h>
using namespace std;

class Heap{

    public :
    int arr[100];
    int size;

    Heap(){
        arr[size] = -1;
        size = 0;
    }

    void insert(int num){
        size = size + 1;
        int index = size;
        arr[index] =  num;

        while(index > 1){
            int parent = index / 2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int  i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){
    Heap hp;
    hp.insert(60);
    hp.insert(50);
    hp.insert(55);
    hp.insert(30);
    hp.insert(20);
    hp.insert(40);
    hp.insert(70);

    hp.print();
}