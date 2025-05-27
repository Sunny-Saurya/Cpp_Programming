#include<bits/stdc++.h>
using  namespace std;

class Queue {
public:
    int *arr;
    int size;
    int front;  // index of front
    int rear;

    Queue() {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return rear == front;
    }

    void enqueue(int data) {
        if (rear == size) {
            return;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if (rear == front) {
            return -1;
        }
        int qFront = arr[front];
        arr[front] = -1;
        front++;

        if (front == rear) {
            front = 0;
            rear = 0;
        }
        return qFront;
    }

    int getFront() {  
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    while (!q.isEmpty()) {
        cout << q.getFront() << " ";  // updated
        q.dequeue();
    }

    cout << "\nQueue is now empty.\n";

    cout << "Front: " << q.getFront() << endl;  // updated

    return 0;
}
