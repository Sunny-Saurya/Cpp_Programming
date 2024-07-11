#include <iostream>
#include <iomanip>
using namespace std;

int squareRoot(int number, int s, int e)
{
    if (s > e)
    {
        return e;
    }

    int mid = s + (e - s) / 2;
    int square = mid * mid;

    if (square == number)
    {
        return mid;
    }
    else if (square > number)
    {
        return squareRoot(number, s, mid - 1);
    }
    else
    {
        return squareRoot(number, mid + 1, e);
    }
}

// Recursive function to add precision
double morePrecisionHelper(int key, double factor, int precision, double ans, int currentPrecision)
{
    if (currentPrecision == precision)
    {
        return ans;
    }

    double nextAns = ans;
    
    for (double j = ans; j * j <= key; j += factor)
    {
        nextAns = j;
    }

    return morePrecisionHelper(key, factor / 10, precision, nextAns, currentPrecision + 1);
}

double morePrecision(int key, int precision, int sq)
{
    double factor = 1.0;
    double ans = sq;
    return morePrecisionHelper(key, factor / 10, precision, ans, 0);
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

    int precision;
    cout << "Enter the precision: ";
    cin >> precision;

    double preciseRoot = morePrecision(number, precision, sq);

    cout << "The square root of " << number << " is: " << fixed << setprecision(precision) << preciseRoot << endl;

    return 0;
}
