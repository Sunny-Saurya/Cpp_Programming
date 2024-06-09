#include<iostream>
#include<climits>

using namespace std;

int SecMaxNumber(int secArr[], int n)
{
    int max = INT_MIN;
    int smax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if( max < secArr[i])
        {
            smax = max;
            max = secArr[i];
        }

        if( smax < secArr[i] && secArr[i] != max)
        {
            smax = secArr[i];
        }
    }
    cout << "Max number is : "  << max << endl;
    cout << "secMax number is : " << smax << " ";
    
}
int main()
{
    int size;
    cout << "Enter Size of an Array: " << " ";
    cin >> size;

    int secArr[100];
    for(int i = 0; i < size; i++)
    {
        cin >> secArr[i];
    }

    SecMaxNumber(secArr , size);
}