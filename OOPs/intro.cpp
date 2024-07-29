#include<iostream>
using namespace std;

class Hero{

    // properties
    public:
    int health; 
    char level;

    void print(){
        cout << "Level: " << level << endl;
    }
};

int main()
{
    // object

    Hero ramesh;

    ramesh.health = 100;
    ramesh.level = 'A';


    cout << "Health of ramesh is  : " <<ramesh.health<< endl; 

    cout << "Level of ramesh is  : " <<ramesh.level<< " "; 

    


    // cout << "Size of h1 : " << sizeof(ramesh);
}