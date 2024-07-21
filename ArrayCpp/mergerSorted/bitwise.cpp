#include<iostream>
using namespace std;

int checkEquality(int n, int k)
{
    if(k > n) return -1;

    int changes = 0;

    while(n > 0 || k > 0)
    {
        int bit_n = n & 1;
        int bit_k = k & 1;

        if(bit_n == 1 && bit_k == 0)
        {
            changes++;
        }
        if(bit_k == 1 && bit_n == 0)
        {
            return -1;
        }

        // right shift

        n >>= 1;
        k >>= 1;
    }
    return changes;
}

int main()
{
    int n;
    cout << "Enter n: " << " ";
    cin >> n;

    int k;
    cout << "Enter k : " << " ";
    cin >> k;

    cout << "Chenges Require to achieve equality is : " << checkEquality(n , k) << " ";
}