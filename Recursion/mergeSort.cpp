#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
    int i, j, k;
    
    int n1 = mid - s + 1;
    int n2 = e - mid;
    
    int l[n1], r[n2];
    
    for(int i = 0; i < n1; i++)
    {
        l[i] = arr[s + i];
    }
    
    for(int  j = 0; j < n2; j++)
    {
        r[j] = arr[mid+1+j];
    }
    
    i = 0; j = 0; k = s;
    
    while(i < n1 && j < n2)
    {
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
    }
    
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int s, int e)
{
    if(s < e)
    {
        int mid = s + (e - s)/ 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

int main()
{
    int n;
    cin >> n;
    
    int arr[100];
    for(int i = 0;  i < n; i++)
    {
        cin >> arr[i];
    }
    
    int s = 0;
    int e = n -1;
    
    mergeSort(arr, s, e);
    
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}