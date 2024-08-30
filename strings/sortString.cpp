#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >>n;
    
    string str[100];
    
    for(int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    cout << "Initial order:"<< " ";

    for(int i = 0; i < n; i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    for(int i = 1; i < n; i++)
    {
        string temp = str[i];
        int j = i -1;
        
        while(j >= 0 && str[j] > temp)
        {
            str[j+1] = str[j];
            j--;
        }
        
        str[j+1] = temp;
    cout << "After Iteration " << i <<": ";
    for(int i = 0; i < n; i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    }
    
    cout << "Sorted order:" << " ";
    for(int i = 0; i < n; i++)
    {
        cout << str[i] << " ";
    }
}
