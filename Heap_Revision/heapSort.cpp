#include<bits/stdc++.h>
using namespace std;

class Heap {

    public:
    int arr[100];
    int size;

    Heap() {
        size = 0;
        arr[0] = -1; // 1-based indexing
    }

    void insert(int num) {
        size = size + 1;
        int index = size;
        arr[index] = num;

        while(index > 1) {
            int parent = index / 2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap() {
        if(size == 0) {
            cout << "Heap is Empty" << endl;
            return;
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size];

        // Step 2: Reduce size
        size--;

        // Step 3: Heapify from root
        int i = 1;
        while(i <= size) {
            int leftNode = 2 * i;
            int rightNode = 2 * i + 1;
            int largest = i;

            if(leftNode <= size && arr[leftNode] > arr[largest]) {
                largest = leftNode;
            }
            if(rightNode <= size && arr[rightNode] > arr[largest]) {
                largest = rightNode;
            }

            if(largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i) {
        int largest = i;
        int leftNode = 2 * i;
        int rightNode = 2 * i + 1;

        if(leftNode <= n && arr[largest] < arr[leftNode]) {
            largest = leftNode;
        }
        if(rightNode <= n && arr[largest] < arr[rightNode]) {
            largest = rightNode;
        }

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n) {
        int size = n;

        while(size > 1) {
            swap(arr[1], arr[size]);
            size--;

            heapify(arr, size, 1);
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap hp;
    hp.insert(60);
    hp.insert(50);
    hp.insert(55);
    hp.insert(30);
    hp.insert(20);
    hp.insert(40);
    hp.insert(70);

    cout << "Heap after insertion: ";
    hp.print();

    hp.deleteFromHeap();
    cout << "Heap after deletion: ";
    hp.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Build Heap
    for(int i = n / 2; i > 0; i--) {
        hp.heapify(arr, n, i);
    }

    cout << "Array after building heap: ";
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    hp.heapSort(arr, n);

    cout << "Array after Heap Sort: ";
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
