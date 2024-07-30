#include<iostream>
using namespace std;

class A{
    public:

    void func(){
        cout << "I am 1" << endl;
    }
};
class B{
    public:

    void func2(){
        cout << "I am 2" << endl;
    }
};

class C: public A, public B{

};

int main()
{
    C obj;
    obj.func();
    
}