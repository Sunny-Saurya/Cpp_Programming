// 90 degree rotate array

// for this question we have to first do transpose of the matrix or array then further we can print it from last to fist

#include<iostream>
using namespace std;

int binarySeach(int arr[][20] ,int key, int n, int m)
{
    int s = 0;
    int e = n*m -1;
    int mid = s + (e-s)/2;
    while(s<=e)
    {
        int element = arr[mid/m][mid%m];

        if(element== key)
        {
            return mid;
        }
        else if (element>key)
        {
            e = mid -1;
        }
        else if (element<key) {
            s = mid +1;
        }
        mid = s + (e-s)/2;
    }
    return -1;

}
    
int main()
{
    int n;
    cout << "Enter rows number : " << " ";
    cin >> n;
    
    int m;
    cout << "Enter cols number : " << " ";
    cin >> m;
    
    int arr[n][20];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cout << "The original array is : " << " ";
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int target;
    cout << "Enter the target number : " << " ";
    cin >> target;
    
    int search = binarySeach(arr,target,n,m);
    cout << "The key is at : " << search << " "; 
}