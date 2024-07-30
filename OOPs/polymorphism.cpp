// existing in multiple form

// ---> two type of polymorphism 
// 1. compile timepolymorphism
// 2. run time polymor...

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


int main(){
    A obj;
    obj.sayHello();
    obj.sayHello("Sunny");
}