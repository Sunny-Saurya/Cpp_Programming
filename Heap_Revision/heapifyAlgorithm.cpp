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

    void deleteFromHeap(){
        
        if(size == 0){
            cout << "Heap is Empty"<< endl;
        }

        // step1 : swap the last node with root node
        arr[1] = arr[size];

        // step2 : delete the  last node
        size--;

        // Step3 : check is it heapify or not

        int i = 1;
        while(i < size){
            int leftNode = 2 * i;
            int rightNode = 2 * i + 1;

            if(leftNode < size && arr[leftNode] > arr[i]){
                swap(arr[leftNode], arr[i]);
                return;
            }
            else if(rightNode < size && arr[rightNode] > arr[i]){
                swap(arr[rightNode], arr[i]);
                return;
            }

            else{
                return;
            }
        }


    }

    void heapify(int arr[], int n, int i){
        int largest = i;
        int leftNode = 2 * i;
        int rightNode = 2 * i + 1;

        if(leftNode < n && arr[largest] < arr[leftNode]){
            largest = leftNode;
        }
        if(rightNode < n && arr[largest] < arr[rightNode]){
            largest = rightNode;
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
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
    hp.deleteFromHeap();


    int arr[6]  = {-1, 54 , 53, 55, 52, 50};
    int n = 5;

    for(int i = n/2; i > 0; i--){
        hp.heapify(arr, n, i);
    }

    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // hp.print();
}