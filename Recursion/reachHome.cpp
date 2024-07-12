#include<iostream>
using namespace std;

void reachHome(int src, int dest)
{
    cout << "The source is " << src << " and  destinaiton is " << dest << endl;
    // base condition
    if(src == dest)
    {
        cout << "Pahuch gya !!" << endl;
        return;
    }
    src++;

    reachHome(src, dest);
}

int main()
{
    int src = 1, dest = 10;

    reachHome(src, dest);
}