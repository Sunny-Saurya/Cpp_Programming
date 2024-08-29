#include <iostream>
using namespace std;

class Deque {
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x) {
        // Check if the deque is full
        if (isFull()) {
            return false;
        }
        // Check if the deque is empty
        else if (isEmpty()) {
            front = rear = 0;
        }
        // Check if the front is at the start and we need to wrap around
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
        }
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x) {
        // Check if the deque is full
        if (isFull()) {
            return false;
        }
        // Check if the deque is empty
        else if (isEmpty()) {
            front = rear = 0;
        }
        // Check if the rear is at the end and we need to wrap around
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront() {
        if (isEmpty()) { // Check if deque is empty
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) { // Single element is present
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0; // To maintain cyclic nature
        }
        else {
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear() {
        if (isEmpty()) { // Check if deque is empty
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) { // Single element is present
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1; // To maintain cyclic nature
        }
        else {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() {
        return (front == -1);
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)));
    }

    // Destructor to clean up dynamically allocated memory
    ~Deque() {
        delete[] arr;
    }
};

int main() {
    Deque dq(5);

    cout << "Insert element at rear end: 5 -> " << dq.pushRear(5) << endl;
    cout << "Insert element at rear end: 10 -> " << dq.pushRear(10) << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    dq.popRear();
    cout << "After deletion, rear element: " << dq.getRear() << endl;

    cout << "Insert element at front end: 15 -> " << dq.pushFront(15) << endl;
    cout << "Front element: " << dq.getFront() << endl;

    dq.popFront();
    cout << "After deletion, front element: " << dq.getFront() << endl;

    return 0;
}
