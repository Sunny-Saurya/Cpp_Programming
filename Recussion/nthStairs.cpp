#include<iostream>
using namespace std;

int nthStairs(int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(n == 0 || n == 1)
    {
        return 1;
    }
    int ans = nthStairs(n - 1) + nthStairs(n - 2);
    return ans;
}

int main()
{
    int stairs;
    cout << "Enter number of stairs: ";
    cin >> stairs;

    int ways = nthStairs(stairs);
    cout << "Total ways: " << ways << endl;

    return 0;
}
