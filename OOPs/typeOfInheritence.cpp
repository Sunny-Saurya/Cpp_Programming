#include<iostream>
using namespace std;


class Animal{

    public:
    int age;
    int weight;

    public:
    void speak(){
        cout << "Speaking " << endl;
    }
};

// single inheritance.

class Dog : public Animal{

};


int main()
{





    return 0;
}