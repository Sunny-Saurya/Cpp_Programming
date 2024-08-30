#include<iostream>
using namespace std;

int count(int arr[], int n){
    int cnt = 0;
    
    for(int i  = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i -1;
        
        while(j >= 0 && arr[j]  > key){
            cnt++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    
    }
    return cnt;
}

int main()
{
    int  n;
    cin >> n;
    
    int arr[100];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int result = count(arr,n);
    cout << result<< " step to sort" << endl;
    
}