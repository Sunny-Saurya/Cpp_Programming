#include<iostream>
#include<math.h>
using namespace std;

int squareRoot(int number,int s, int e)
{
    int mid = s + (e - s)/2;
    int ans = -1;

    if(s > e)
    {
        return e;
    }

    int square = mid * mid;

    if(square == number)
    {
        return mid;
    }
    if(square > number)
    {

        return squareRoot(number, s, mid - 1);

    }
    if(square < number)
    {
        
        return squareRoot(number , mid + 1, e);

    }

    
}

int main()
{
    int number;
    cout << "Enter any number: ";
    cin >> number;

    if (number < 0)
    {
        cout << "Square root is not defined for negative numbers." << endl;
        return -1;
    }

    int s = 0;
    int e = number;
    int sq = squareRoot(number, s, e);

    cout << "The square root of " << number << " is: " << sq << endl;

    return 0;
}