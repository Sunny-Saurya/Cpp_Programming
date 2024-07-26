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
    Hero h1;

    cout << "Hero health is : " << h1.getHealth() << endl;  // print the garbage value 


    h1.setHealth(80);
    h1.level = 'A';

    cout << "Health is : " << h1.getHealth() << endl; /// print the actual value i.e 80
    cout << "Level is : " << h1.level << endl;
    // cout << "Size of Hero : " << sizeof(h1) << " "; 
}