// INsertion sort

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp = arr[i];
        int j;

        for(j = i -1; j >= 0; j--)
        {
            if(arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int n;
    cout <<"Enter the size of an array : "  << " ";
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
         cin >> arr[i];
    }

    cout << "Entered array is : " << " ";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    insertionSort(arr, n);

    cout <<"The sorted array is : " << " ";

    for(int i = 0; i< n; i++)
    {
        cout << arr[i] << " ";
    }

}