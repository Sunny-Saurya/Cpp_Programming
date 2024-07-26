#include<iostream>
using namespace std;

class Hero{

    // properties

    public:     // this mean you can access the value of health and level anywhere in the code
    int health;

    // private:    // this means you can only access the value inside this class
    char level;

    void print(){
         cout << "Level is : " << level << endl;
    }



};

int main()
{
    Hero h1;

    h1.health = 80;
    h1.level = 'A';

    cout << "Health is : " << h1.health << endl;
    cout << "Level is : " << h1.level << endl;
    // cout << "Size of Hero : " << sizeof(h1) << " "; 
}