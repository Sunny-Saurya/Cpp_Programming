// AGGRESSIVE COWS -> place the cows at the maximum distance with each other so that they cant agressive to each other.

#include<iostream>
using namespace std;

bool isPossible(int arr[], int n , int m, int mid)
{
    int cowsCount = 1;
    int lastPos = arr[0];

    for(int i =0; i < n; i++)
    {
        if(arr[i] - lastPos  >=mid)
        {
            cowsCount++;
            if(cowsCount == m)
            {
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}

int allocateStallsToCow(int arr[], int n, int m)
{
    
    int s = 0;
    int maxi = -1;

    for(int i = 0 ; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int e = maxi;
    int ans = -1;
    int mid =  s + (e-s)/2;

    while (s <= e)
    {
        if(isPossible(arr, n,m, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    mid = s + (e - s)/2;
    }
    
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of stalls: " << " ";
    cin >> n;

    int arr[100];

    cout << "Enter the value in sorted manner : " << " ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int m;
    cout << "Enter number of cows : " << " ";
    cin >> m;

    int distance = allocateStallsToCow(arr , n, m);
    cout << "The maximum distance is : " << distance << " ";
}