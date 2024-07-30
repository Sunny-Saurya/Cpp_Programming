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

// multi level inheritance.

class Dog : public Animal{

};


class GermanShepherd: public Dog{

};

int main()
{





    return 0;
}