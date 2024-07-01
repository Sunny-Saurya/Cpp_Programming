//***************ARRAY CONCEPT****************

// ARRAY ? ===> An array is a collection of items of similar type stored in collection memory location.
// Sometimes a simple variable is not enough to hold all the data.

// For  Example. lets say we want to store the marks of 3500 students, having 3500 differnet varibale for this task is not feasible.
// To hold this problem, we can define an array with size 3500 that can hold the marks of all stundents.
// syntax of array ==> datatype arrayname[size]

// We can access the array's elements by the help of index.

// #include<iostream>
// using namespace std;

// int main(){
//     int array[5] = { 12,23,45,676,87};

//     cout<<array[3];
//     return 0;
// }

// How to take array from the user.

/*#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    int array[n];
    
    for (int  i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }

    return 0;
}*/

// Take an array from the user and size n and find the maximum and minimum element given by the user.

// #include<iostream>
// #include<climits>
// using namespace std;

// int main(){
//     int n;
//     cout<<"Enter the size of an array"<<endl;
//     cin>>n;

//     for (int i = 0; i < n; i++)
//     {
//         cin>>array[i];
//     }

//     int maxNo = INT_MIN;
//     int minNo = INT_MAX;


//     for (int i = 0; i < n; i++)
//     {
//         maxNo = max(maxNo, array[i]);
//         minNo = min(minNo,array[i]);
       
//     }
//     cout<<maxNo<<endl;
//     cout<<minNo<<endl;

//     return 0;
// }


#include<iostream>
using namespace std;

int main(){

    // EXAMPLE OF AN ARRAY.

    int marks[4] = { 23,45,56,89};

    int mathMarks[4];

    mathMarks[0] = 45;
    mathMarks[1] = 55;
    mathMarks[2] = 85;
    mathMarks[3] = 32;
    cout<<"these are maths marks"<<endl;

    cout<<mathMarks[0]<<endl;
    cout<<mathMarks[1]<<endl;
    cout<<mathMarks[2]<<endl;
    cout<<mathMarks[3]<<endl;

    // you can change the value of an array.
    marks[2] = 876;
    
    // cout<<"these are marks"<<endl;

    // cout<<marks[0]<<endl;
    // cout<<marks[1]<<endl;
    // cout<<marks[2]<<endl;
    // cout<<marks[3]<<endl;

    // FOR LOOP .

    // for (int  i = 0; i < 4; i++)
    // {
    //     cout<<"the value of marks by using for loop"<< marks[i]<<endl;
    // }
    
    // WHILE LOOP

    // int i = 0;
    // while (i<4)
    // {
    //     cout<<"the value of marks by using while loop"<<i<< marks[i]<<endl;
    //     i++;
    // }

    // DO WHILE LOOP
    
    // int i = 0;
    // do
    // {
    //     cout<<"the value of marks by using while loop"<< marks[i];
    //     i++;
    // } while (i<4);
    
    //Pointer and arrays
    int*p = marks;
    cout<<*(p++);
    // cout<<"The value of *p is :"<<*p;
    // cout<<"The value of *(p+1)is :"<<*(p+1);
    // cout<<"The value of *(p+2) is :"<<*(p+2);
    // cout<<"The value of *(p+3) is :"<<*(p+3);

    return 0;
}