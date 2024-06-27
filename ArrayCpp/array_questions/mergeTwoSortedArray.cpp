// merge two sorted array

#include <iostream>
using namespace std;

int merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }

    while (i < n)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }

    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

int printArray(int ans[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    }
int main()
{
    int n;
    cout << "Enter size of first array : " << " ";
    cin >> n;

    int arr1[n];
    // cout << "Enter elements of first array : " << " ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << endl;

    cout << "Element of first array are : " << " ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << endl;
    int m;
    cout << "Enter size of second array : " << " ";
    cin >> m;

    int arr2[m];
    // cout << endl;
    // cout << "Enter elements of second array : " << " ";

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << endl;

    cout << "Element of second array are : " << " ";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }

    int arr3[m + n] = {0};

    merge(arr1, n, arr2, m, arr3);
    cout << endl;
    cout <<"The final array of merged two sort array is : " << " ";
    printArray(arr3, m + n);
}