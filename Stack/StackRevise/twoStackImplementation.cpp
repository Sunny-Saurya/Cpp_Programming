#include<bits/stdc++.h>

using namespace std;

class TwoStack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;


    TwoStack(int size){
        this -> size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int element){
        if(top1 < top2-1){
            top1++;
            arr[top1] = element;
        }
        else{
            cout << "Stack 1 Overflowed !!" << endl;
        }
    }

    void push2(int element){
        if(top1 < top2-1){
            top2--;
            arr[top2] = element;
        }
        else{
            cout << "Stack 2 Overflowed !!" << endl;
        }
    }

    void pop1(){
        if(top1 != -1){
            top1--;
        }
        else{
            cout << "Stack 1 underflowed !!" << endl;
        }
    }

    void pop2(){
        if(top2 < size){
            top2++;
        }
        else{
            cout << "Stack 2 underflowed !!" << endl;
        }

    }

    bool isEmpty1(){
        if(top1 == -1){
            return true;
        }
        return false;
    }

     bool isEmpty2(){
        if(top2 == size){
            return true;
        }
        return false;
    }


    int peek1(){
        if(top1 != -1){
            return arr[top1];
        }else{
            cout << "Stack 1 is Empty";
            return -1;
        }
    }

    int peek2(){
        if(top2 != size){
            return arr[top2];
        }
        else{
            cout << "Stack 2 is Empty";
            return -1;
        }
    }
};

int main(){
    TwoStack st(5);

    st.push1(1);
    st.push2(2);
    st.push1(3);
    st.push2(4);

    cout << "Top of Stack 1: " << st.peek1() << endl;
    cout << "Top of Stack 2: " << st.peek2() << endl;

    st.pop1();
    st.pop2();

    cout << "After popping:\n";
    cout << "Top of Stack 1: " << st.peek1() << endl;
    cout << "Top of Stack 2: " << st.peek2() << endl;

    cout << "Is Stack 1 Empty? " << (st.isEmpty1() ? "Yes" : "No") << endl;
    cout << "Is Stack 2 Empty? " << (st.isEmpty2() ? "Yes" : "No") << endl;

    return 0;
    
}