// modular Exponentiation

// you are give a three x , n and m. you task is to find (x ^ n) %m.

#include<iostream>
using namespace std;


int modularExpo(int x, int n, int m)
{
    int res = 1;

    while (n > 0)
    {
        /* code */
        if(n & 1) // odd
        {
            res = (1LL * (res )* (x) % m) % m;
        }
        x = (1LL * (x) % m * (x) %m)%m;
        n = n >> 1;
    }
    return res;
    
}
int main()
{
    int x;
    cout << "Enter number x : " << " ";
    cin >> x;

    int n;
    cout << "Enter number n : " << " ";
    cin >> n;

    int m;
    cout << "Enter number m : " << " ";
    cin >> m;

   int ans =  modularExpo(x, n,m);
   cout << "The answer is : " << ans << " ";
}