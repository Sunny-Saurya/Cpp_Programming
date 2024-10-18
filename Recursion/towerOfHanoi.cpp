#include<bits/stdc++.h>
using namespace std;

int totalCount(int n)
{
    return pow(2,n) - 1;
}

void towerOfHanoi(int n, char source, char aux, char dest)
{
    if(n == 1)
    {
        cout << "Move disk 1 from source " << source << " to destination " << dest;
        return;
    }
    towerOfHanoi(n-1, source, dest, aux);
    cout << "\nMove disk " << n << " from source " << source << " to"  << " destination " << dest << endl;
    towerOfHanoi(n-1, aux, source, dest);

}

int main()
{
    int n;
    cin >> n;

    int ans = totalCount(n); 
    cout << "Total no. of shifting are : " << ans << " ";
    cout << endl;
    towerOfHanoi(n, 'A', 'B',  'C');
    return 0;
}

