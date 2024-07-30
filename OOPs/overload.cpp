#include<iostream>
using namespace std;


class A{
    public:
    void sayHello(){
        cout << "Hello Sunny Kumar" << endl;
    }

    void sayHello(string name){
        cout << "Hello " << name  << endl;
    }
};

class B {
    public:

    int a;
    int b;

    public:
    
    int add (){
        return a + b;
    }

    void operator+ (B &obj)
    {
        int value1 = this->a;
        int value2 = obj.b;

        cout << "Output is : " << value2 - value1 << endl;
    }
};


int main()
{
    
    B obj1, obj2;
    obj1.a = 4;
    obj2.b = 7;

    obj1 + obj2;
}