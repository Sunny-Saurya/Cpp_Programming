// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void InsertinSort(int arr[], int n)
{
    // for(int i = 1; i < n; i++)
    // {
    //     int temp = arr[i];
    //     int j;
        
    //     for(j = i - 1; j >= 0; j--)
    //     {
    //         if(arr[j] > temp)
    //         {
    //             arr[j+1] = arr[j];
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     arr[j+1]  = temp;
    // }
    
    int i = 1;
    while(i < n)
    {
         int j,temp;
        temp = arr[i];
        j = i -1;
        while(j >=0 )
        {
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}

int main() {
    // Write C++ code here
    int n;
    cout << "Enter the size of an array : " << " ";
    cin >> n;
    
    int arr[100];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    InsertinSort(arr, n);
    
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}