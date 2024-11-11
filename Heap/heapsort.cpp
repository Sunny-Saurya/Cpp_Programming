#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    // Constructor
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // Function to insert a value into the heap
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n )
{

    for(int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    int size = n;

    while(size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(25);
    cout << "Max-Heap from insertions: ";
    h.print();

    int arr[6] = {-1, 54, 53, 52, 51, 56}; 
    int n = 5;

    // Applying heap sort on the array

    heapSort(arr, n);

    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
