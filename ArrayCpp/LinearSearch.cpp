#include<iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for(int i = 0; i < size; i++)
    {
        if(key == arr[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cout<<"Enter size of an array: "<<" ";
    cin>>n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout<< arr[i] << " ";
    }

    int key;
    cout<<"Enter key that you want to find : "<< " ";
    cin>>key;

    bool result = search(arr, n, key);
    if(result)
    {
        cout<<"Key is present"<<endl;
    }
    else cout<<" Key is absent"<<endl;

}