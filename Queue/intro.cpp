#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;

    cout << "Size of Queue : " << q.size() << endl;

    q.pop();
    cout << "Size : " << q.size() << endl;

    if(q.empty()){
        cout << " Queue is empty " << endl;
    }
    else{ 
        cout << "Queue is not empty " << endl;
    }

}