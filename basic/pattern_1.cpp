/* #include<iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of colums: ";
    cin>>col;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<'*'<<" ";
        }
        cout<<endl;  
    }
    
} */

// ------------------By using while loop-------------------

#include<iostream>
using namespace std;

int main()
{
    int row,col;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of colums: ";
    cin>>col;
    
    int i = 0;

    while (i<row)
    {
        int j = 0;
        while (j<col)
        {
            cout<<'*'<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout<<'*'<<" ";
    //     }
    //     cout<<endl;  
    // }
    
}