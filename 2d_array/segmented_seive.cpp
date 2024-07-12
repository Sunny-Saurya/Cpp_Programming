// segmented seive;

#include<iostream>
using namespace std;

int segementedSeive(int n)
{
    for(int i = 0; i < n; i++)
    {
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        if(isPrime(mid))
    }
}
int main()
{
    int n;
    cout << "Enter number : " << " ";
    cin>>n;

    segementedSeive(n);
}