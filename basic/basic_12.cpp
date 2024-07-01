// 1. Question of pattern printing
/*#include<iostream>
using namespace std;

int main(){
    int n,i,j;
    cout<<"Enter the number of rowss";
    cin>>n;

    i =  1;
    while(i<=n)
    {
        j = 1;
        while(j<=i)
        {
            cout<<'*';
            j++;
        }
        cout<<"\n";
        i++;
        
    }

    return 0;
}*/

//************By using For loop**************
/*#include<iostream>
using namespace std;

int main(){
    int n,j,i;
    cout<<"Enter the number of rows : ";
    cin>>n;

    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=i; j++)
        {
            cout<<'*';

        }
        cout<<"\n";
    }
    return 0;
}*/

// Question no. 2 of printing shape;
/*#include<iostream>
using namespace std;

int main(){
    int n,i,j,b;
    cout<<"Enter the number of rows : ";
    cin>>n;

    i = 1;
    while(i<=n)
    {
        b = 1;
        while(b<=n-i)
        {
            cout<<" ";
            b++;
        }
        j = 1;
        while(j<=i)
        {
            cout<<"*";
            j++;
        }
        cout<<"\n";
        i++;
    }
    
    return 0;
}*/

//*******************BY USING FOR LOOP***************
//  #include<iostream>
//  using namespace std;
 
//  int main(){
//     int n,i,j,b;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(i = 1; i <= n; i++)
//     {
//         for(b = 1; b<=n-i; b++){
//             cout<<" ";
//         }
//         for(j = 1; j<=i; j++)
//         {
//             cout<<"*";
//         }
//         cout<<"\n";

//     }
//     return 0;
//  }

// QUESTION NO. 3 OF PRINTING SHAPE.
// #include<iostream>
// using namespace std;

// int main(){
//     int n,i,j,b;
//     cout<<"Enter the numner of rows :";
//     cin>>n;

//     i = 1;
//     while(i<=n)
//     {
//         b = 1;
//         while(b<=n-i)
//         {
//             cout<<" ";
//             b++;
//         }
//         j = 1;
//         while(j<=2*i-1)
//         {
//             cout<<j;
//             j++;
//         }
//         cout<<"\n";
//         i++;
//     }
//     return 0;
// }

//*****************BY USING FOR LOOP******************
// #include<iostream>
// using namespace std;

// int main(){
//     int n,i,j,b;
//     cout<<"Enter the number of rows :";
//     cin>>n;

//     for(i = 1; i<= n; i++)
//     {
//         for(b = 1; b <= n-i; b++)
//         {
//             cout<<" ";
//         }
//         for(j= 1; j<=2*i-1; j++)
//         {
//             cout<<"*";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main(){
//     int n,i,j,b;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     i = n;
//     while(i>0)
//     {
//         b = 1;
//         while(b<=n-i)
//         {
//             cout<<" ";
//             b++;
//         }
//         j = 0;
//         while(j<i)
//         {
//             cout<<"*";
//             j++;
//         }
//         cout<<"\n";
//         i--;
//     }
//     return 0;
// }


// Shape of inverted pyramid.

// #include<iostream>
// using namespace std;

// int main(){
//     int n,i,j,b;
//     cout<<"Enter the number of  rows : ";
//     cin>>n;

//     i = n;
//     while(i>0){
//         b = 1;
//         while(b <= n - i)
//         {
//             cout<<" ";
//             b++;
//         }
//         j = 1;
//         while(j<=2*i-1)
//         {
//             cout<<"*";
//             j++;
//         }
//         cout<<"\n";
//         i--;
//     }
//     return 0;
// }

