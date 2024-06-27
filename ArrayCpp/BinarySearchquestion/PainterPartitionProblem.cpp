// painter partition problem

#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{
    int painterCount = 1;
    int boardCount = 0;

    for(int i = 0; i < n; i++)
    {
        if(boardCount + arr[i] <= mid)
        {
            boardCount += arr[i];
        }
        else{
            painterCount++;
            if(arr[i] > mid || painterCount > m)
            {
                return false;
            }
        boardCount = arr[i];
        }
    }
    return true;

}

int allocateBoard(int arr[], int n, int m)
{
    int s = 0; 
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int e = sum;

    int mid = s + (e - s)/2;
    int ans = -1;

    while (s <= e)
    {
        if(isPossible(arr,n,m,mid))
        {
            ans = mid;
            e = mid -1;
        }

        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of paintBoard : " << " ";
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cout << "Enter number of painters : " << " ";
    cin >> m;

    int minTimeTaken = allocateBoard(arr, n, m);
    cout << "The minimum time taken by the painter is : " <<  minTimeTaken << " ";
}