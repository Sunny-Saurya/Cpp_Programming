#include<iostream>
using namespace std;

class Hero{

    // properties

    private:       
    int health;

    
    public:   
    char level;

    // Constructor --> if we create our own constructor then the default constructor will be deminish and new constructor is your constructor that you create

    Hero(){
        cout<<"Constructor called"<<endl;
    }

    // constructor with parameter 

    Hero(int health, char level){
        cout << "this -> " << this << endl;
        this -> health = health;
        cout << "this -> " << this << endl;
        this -> level = level;
    }

    // copy constructor

    Hero(Hero& temp){
        this -> health  = temp.health;
        this -> level  = temp.level;
    }

    


    void print(){
         cout << "Health is : " << this->health << endl;
         cout << "Level is : " << this->level << endl;
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
    Hero h2(100, 'C');
    h2.print();

    // copy contructor

    Hero h3(h2);
    h3.print();

















    // static allocation
    // Hero h1(122);  // call contructor
    // cout << "Address of h1 " << &h1 << endl;
    // h1.setHealth(10);
    // h1.setLevel('A');

    // cout << "level is : " << h1.getLevel() << endl;
    // cout << "health is : " << h1.getHealth() << endl;
    // // dynamic allocation

    // Hero *b = new Hero; // call contructor
    // b->setHealth(80);
    // b->setLevel('A');

    // cout << "level is : " << b->getLevel() << endl;
    // cout << "health is : " << b->getHealth() << endl;
}