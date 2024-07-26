#include<iostream>
using namespace std;

class Hero{

    // properties

    private:       
    int health;

    
    public:   
    char level;

    void print(){
         cout << "Level is : " << level << endl;
    }


    // now we can not the value of health in the main function but by using getter and setter fucntion we can access that.

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    }


};

int main()
{
    // static allocation
    Hero h1; 
    h1.setHealth(10);
    h1.setLevel('A');

    cout << "level is : " << h1.getLevel() << endl;
    cout << "health is : " << h1.getHealth() << endl;
    // dynamic allocation

    Hero *b = new Hero;
    b->setHealth(80);
    b->setLevel('A');

    cout << "level is : " << b->getLevel() << endl;
    cout << "health is : " << b->getHealth() << endl;
}