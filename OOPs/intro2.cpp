#include <iostream>
using namespace std;

class Hero
{
    // properties
public:
    int health;

private:
    char level;


// constructor
public:
Hero(){
    cout << "Constructor called" << endl;
}    


// parameterised constructor

Hero(int health){
    cout << "Address of this : " << this << endl;
    this -> health = health;
}

Hero (int health, char level)
{
    this->level = level;
    this -> health = health;
}


public:
    void print()
    { 
        cout << "Health: " << health << endl;  
        cout << "Level: " << level << endl;
    }

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }
};

int main()
{   

    Hero suresh(70, 'C');
    suresh.print();

    // copy contructor;

    Hero s1(suresh);
    s1.print();



















    // // cout << "HII" << endl;
    // Hero suresh;
    // // cout << "Everyone" << endl;
    // cout << "Address of suresh :  " << &suresh << endl;
    // suresh.getHealth();d

    // // Hero *h1 = new Hero;



















    // object
    // Hero ramesh;

    // // Initially, health and level might have garbage values
    // cout << "Initial health of ramesh is : " << ramesh.getHealth() << endl;
    // ramesh.setHealth(79);
    // ramesh.setLevel('A');

    // cout << "Updated health of ramesh is  : " << ramesh.getHealth() << endl;
    // cout << "Level of ramesh is  : " << ramesh.getLevel() << endl;

    // // If you want to print the size of the object
    // cout << "Size of ramesh: " << sizeof(ramesh) << endl;

    return 0;
}
