#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: " << " ";
    cin >> n;

    int arr[100];
    for(int i = 0; i < n; i++)
    {
        
        cin >> arr[i];
    }

    queue<int>q;

    for(int i = 0;i <n; i++)
    {
        q.push(arr[i]);
    }

    int k;
    cout << "Enter K to reverse: " << " ";
    cin >> k;

    // step 1. push first kth element to stack
    stack<int> s;

    for(int i = 0; i < k; i++)
    {
        int val = q.front();
        s.push(val);
        q.pop();
    }

    // step 2: push element of stack to the queue;

    while (!s.empty())  
    {
        /* code */
        q.push(s.top());
        s.pop();
    }

    
    // step 3: pushBack (n-k) element  to the last of queue
    
    int t = q.size() - k;
    while(t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    cout << "Queue after Kth reversal : " << " ";

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}