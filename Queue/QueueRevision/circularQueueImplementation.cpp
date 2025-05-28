#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int data){
        // check if it is empty or not

         if ((rear + 1) % size == front) {
            cout << "Queue is full!" << endl;
            return false;
        }

        // Inserting the first element
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = data;
        return true;
    }

    int dequeue(){
        // check if it is full or not

        if(front == -1 && rear == -1){
            cout << "Nothing can be Popped coz queue is EMpty now !!";
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // for single elemenet

        if(front == rear){
            front = rear = -1;
        }

        else if(front == size -1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
    bool isEmpty(){
        // if(rear == -1 && front == -1){
        //     return false;
        // }
        // return true;

        return front == -1;
    }
    
    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
};

int main(){
    CircularQueue q(3);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(7);

    while(!q.isEmpty()){
        cout << q.getFront() << " ";
        q.dequeue();
    }
}