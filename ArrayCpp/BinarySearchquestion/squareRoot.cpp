// square root

#include<iostream>
using namespace std;

int sqrtInteger(int key)
{
    int s = 0;
    int e = key;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;

    while (s <= e)
    {
        long long int square = mid * mid;
        if(key == square)
        {
            return mid;
        }

        else if(key > square )
        {
            ans = mid;
            s = mid + 1;
        }

        else if(key < square)
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;

}

double morePrecision(int key, int precision, int squareRoot)
{
    double factor = 1;
    double ans = squareRoot;

    for(int i = 0; i < precision; i++)
    {
        factor  = factor/10;

        for(double j = squareRoot; j * j < key; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int key;
    cout << "Enter key : " << " ";
    cin >> key;

    int squareRoot = sqrtInteger(key);
    cout << "Square root of " << key << " is " << morePrecision(key,3,squareRoot) << endl;
}