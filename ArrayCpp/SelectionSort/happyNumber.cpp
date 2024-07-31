// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isHappyNumber(int n)
{
    while(true)
    {
        int sum = 0;
        while(n > 0)
        {
            int rem = n % 10;
            sum = sum + rem * rem;
            n = n/10;
        }
        
    if(sum == 1) return true;
    if(sum == 4) return false;
    n = sum;
    }
}

int main() {
    // Write C++ code here
    int n;
    cout << "Enter  number : " << " ";
    cin >> n;
    
    cout << isHappyNumber(n)  << ' ';

    return 0;
}