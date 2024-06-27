#include<iostream>
#include<vector>
using namespace std;

vector <int> reverse(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;

    while (s <= e)
    {
        /* code */
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}

int  printArray(vector<int> v)
{
    for(int i = 0; i <= v.size()-1; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v;

    v.push_back(12);
    v.push_back(32);
    v.push_back(5);
    v.push_back(76);
    v.push_back(43);

    vector<int> arr = reverse(v);

    printArray(arr);


}