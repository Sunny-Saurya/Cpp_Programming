#include<bits/stdc++.h>
using namespace std;

void sortedInsertion(stack<int>&st, int num)
{
    if(st.empty() || st.top() <= num){
         st.push(num);
         return;
    }

    int top = st.top();
    st.pop();

    sortedInsertion(st, num);

    st.push(top);
}

void sortStack(stack<int> &st){

    if(st.empty()){
        return;
    }


    int top = st.top(); 
    st.pop();

    sortStack(st);

    sortedInsertion(st, top);

}

int main(){

    stack<int> st;

    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    st.push(9);

    sortStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
       }
}