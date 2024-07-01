// function ==> Do once use whenever.apne program ko tukdo  me tod do or alag alag tukdo se alag alag kaam kaarwao.

/*#include<iostream>
using namespace std;

int sum(int a, int b)
{
    int c = a+b;
    return c;
}
int main(){
    int num1,num2;
    cout<<"Enter first number"<<endl;
    cin>>num1;
    cout<<"Enter second number"<<endl;
    cin>>num2;
    cout<<"the sum of num1 and num2 is  ==> "<< sum(num1,num2);
    return 0;
}*/ 

// #include<iostream>
// using namespace std;

// int sum (int a, int b); // function prototype ==> it gives assuraty.
// //int sum (int a, int b); ===> Acceptable
// // int sum(int, int); ===> Acceptable
// // int sum(int a,b); ===> Not acceptable


// int main(){
//     int num1,num2;
//     cout<<"Enter first number"<<endl;
//     cin>>num1;
//     cout<<"Enter second number"<<endl;
//     cin>>num2;
//     // num1 and num2 are acctuall parameter.
//     cout<<"the sum of num1 and num2 is  ==> "<< sum(num1,num2);
//     return 0;
// }

// int sum(int a, int b)
// {
    // Formal Parameters a and b will be taking values from actual parameters num1 and num2
//     int c = a+b;
//     return c;
// }


//**************************************************************

// #include<iostream>
// using namespace std;

// int sub(int a, int b){
//     int c = a-b;
//     return c;
// }
// int main(){
//     int num1,num2;
//     cout<<"Enter two number";
//     cin>>num1>>num2;

//     cout<<"The subtraction is ===> "<<sub(num1,num2);
//     return 0;
// }

// #include<iostream>
// using namespace std;

// float mul(float a, float b){
//     float c = a*b;
//     return c;
// }
// int main(){
//     float num1, num2;
//     cout<<"Enter two number";
//     cin>>num1>>num2;


//     cout<<"The multiplication is ==> "<<mul(num1,num2);
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int division(int,int); // prototype

// int main(){
//     int num1,num2;
//     cout<<"Enter two number";
//     cin>>num1>>num2;

//     cout<<"The division is ==> "<<division(num1,num2);
//     return 0;
// }
// int division( int a, int b){
//     float c = a/b;
//     return c;
// }

// // FIBONACCI SERIES PROBLEM SOLVING BY USING FUNCTIONS.
// #include<iostream>
// using namespace std;

// void fib(int n){
//     int t1 = 0;
//     int t2 = 1;
//     int nextTerm;

//     for(int i = 1; i<=n; i++)
//     {
//         cout<<t1<<endl;
//         nextTerm= t1+t2;
//         t1 = t2;
//         t2 = nextTerm;
//     }
//     return;
// }
// int main(){
//     int n;
//     cout<<"Enter the number of terms";
//     cin>>n;

//     fib(n);
//     return 0;
// }

// #include<iostream>
// using namespace std;

// void power(int x, int y)
// {
//     int pro = 1;
//     for(int i = 1; i<=y; i++)
//     {
//         pro = pro * x;
//         cout<<pro;
//     }
//     return;
// }
// int main(){
//     int x,y;
//     cout<<"Enter the value of x and y";
//     cin>>x>>y;

//     power(int x, int y);
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int fact(int n){
//     int factorial =1 ;
//     for(int i = 1; i<=n; i++)
//     {
//         factorial = factorial * i;
//     }
//     return factorial;
// }
// int main(){
//     int n;
//     cin>>n;

//     int ans = fact(n);
//     cout<<ans<<endl;
//     return 0;
// }

//CALULATTE nCr

// #include<iostream>
// using namespace std;

// int fact (int n){
//     int factorial = 1;
//     for(int i = 1; i<=n; i++)
//     {
//         factorial = factorial * i;
//     }
//     return factorial;
// }
// int main(){
//     int n,r;
//     cin>>n>>r;

//     int ans = fact(n)/(fact(r)*fact(n-r));
//     cout<<ans;
//     return 0;
// }
//PASCAL TRIANGLE OR PATTERN PRINTING QUESTION.
'''#include<iostream>
using namespace std;

int fact (int n){
    int factorial = 1;
    for(int i = 2; i<=n; i++){
        factorial = factorial * i;

    }
    return factorial;
}
int main(){
    int n;
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
        }
        cout<<endl;
    }
    return 0;
}'''

