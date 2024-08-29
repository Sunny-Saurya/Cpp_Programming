#include <iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Check whether the queue is full
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
            return false;
        }
        else if(front == -1) { // First element to push
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0; // To maintain cyclic nature
        }
        else { // Normal flow
            rear++;
        }
        // Push inside the queue
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){ // To check if queue is empty
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { // Single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; // To maintain cyclic nature
        }
        else { // Normal flow
            front++;
        }
        return ans;
    }

    // Utility function to display the queue
    void display(){
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Elements in the circular queue are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(6);

    q.display();

    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    q.display();

    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);

    q.display();

    return 0;
}
