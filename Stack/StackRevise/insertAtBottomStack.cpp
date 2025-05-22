#include<bits/stdc++.h>
using namespace std;

stack<int> pushAtBottom(stack<int>& input, int x) {
    // Base case
    if (input.empty()) {
        input.push(x);
        return input;
    }

    int top = input.top();
    input.pop();

    pushAtBottom(input, x);  // Recursive call

    input.push(top);  // Restore the top element

    return input;
}


int main(){

    stack<int> st;

    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);

    pushAtBottom(st, 10);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


}