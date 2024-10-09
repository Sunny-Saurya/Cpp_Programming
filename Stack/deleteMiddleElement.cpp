#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &st, int count, int n)
{
    if(count == n/2){
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    deleteMiddle(st, count+1, n);
    st.push(temp);
}

void printStack(stack<int> st)
{
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> st;

    int n;
    cout << "Enter size: " << endl;
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        st.push(arr[i]);
    }

    int count = 0;

    deleteMiddle(st,count, n);
    printStack(st);
    

    
}