#include<iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;
    
    int arr[100];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n -1; i++)
    {
        int max = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[max] < arr[j]){
                max = j;
            }
        }
        if(max != i){
            swap(arr[i], arr[max]);
        }
    cout << "After his step: "<<i+1 << endl;
    for(int k = 0; k < n; k++)
    {
        cout <<arr[k]<< " ";
    }
    cout << endl;
    }
    
    cout << "Finally, he got it" << endl;
    for(int i = 0; i < n; i++)
    {
        cout <<arr[i] <<" ";
    }
    
    
}