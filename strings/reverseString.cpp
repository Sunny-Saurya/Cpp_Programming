#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string str[100];
    
    for(int i  = 0; i < n; i++)
    {
        cin >> str[i];
    }
    
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(str[j]> str[j+1]){
                swap(str[j], str[j+1]);
            }
        }
    }
    for(int i = 0; i < n ; i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
}