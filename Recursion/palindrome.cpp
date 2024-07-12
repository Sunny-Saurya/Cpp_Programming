// #include<iostream>
// using namespace std;

// bool checkPalidrome(string str, int i , int j)
// {
//     if(i > j)
//     {
//         return true;
//     }
//     if(str[i] != str[j])
//     {
//         return false;
//     }
//     else{
//         return checkPalidrome(str, i+1, j-1);
//     }
// }

// int main()
// {
//     string str;
//     cout << "Enter string : " << " ";
//     getline(cin, str);

//     int i = 0;
//     int j = str.length() - 1;
//     bool isPalidrome = checkPalidrome(str,i , j );

//     if(isPalidrome){
//         cout << "It's a Palindrome" << endl;
//     }
//     else{
//         cout << "It's not a Palindrome" << endl;
//     }
// }


// can we optimize it by passing only two para into the function 


#include<iostream>
using namespace std;

bool checkPalidrome(string str, int i)
{
    int j = str.length() - 1;
    if(i > j)
    {
        return true;
    }
    if(str[i] != str[j])
    {
        return false;
    }
    else{
        return checkPalidrome(str,str[i+1] );
    }
}

int main()
{
    string str;
    cout << "Enter string : " << " ";
    getline(cin, str);

    int i = 0;
    bool isPalidrome = checkPalidrome(str,i );

    if(isPalidrome){
        cout << "It's a Palindrome" << endl;
    }
    else{
        cout << "It's not a Palindrome" << endl;
    }
}