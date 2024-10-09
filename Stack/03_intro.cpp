#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    vector<int> arr;
    // printing stack

    cout << "Priting stack : ";
    while(!st.empty())
    {
        cout << st.top() << " ";
        arr.push_back(st.top());
        st.pop();
    }
    cout << endl;

    // reversing stack

    cout << "After reversing stack : ";

    for(int i = arr.size() -1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


}