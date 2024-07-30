#include<iostream>
using namespace std;

class Human {

    public:

    float height;
    int weight;
    int age;


    public:
    int getAge(){
        return this->age;
    }

    float setHeight(float h){
        this->height = h;
    }

    int setWeight(int w){
        this->weight = w;
    }
};


//inheritence

class Male: public Human {
    public:
    string color;

    void sleep()
    {
        cout << " Male Sleeping " << endl;
    }
};

int main()
{

    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;
    cout << object1.color << endl;

    object1.setWeight(85);
    cout <<"Weight is : "<<  object1.weight<< endl;

    object1.setHeight(5.4);
    cout <<"Height is : "<<  object1.height<< endl;
    object1.sleep();


    return 0;
}