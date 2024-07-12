// #include<iostream>
// using namespace std;

// void reverse(string &str, int i, int j)
// {
//     // base case
//     if(i > j)
//     {
//         return;
//     }
//     swap(str[i], str[j]);
//     i++;
//     j--;
//     reverse(str, i , j);
// }

// int main()
// {
//     string str;
//     cout << "Enter your string: ";
//     getline(cin, str);

//     int i = 0;
//     int j = str.length() - 1;
//     reverse(str, i, j);

//     cout << "The reversed string is: " << str << endl;
//     return 0;
// }


// we can more optimize it by passing only two parameter into the functions

#include<iostream>
using namespace std;

void reverse(string &str, int i)
{
    int n = str.length();
    // base case
    if(i >= n / 2)
    {
        return;
    }
    swap(str[i], str[n - i - 1]);
    reverse(str, i + 1);
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);

    reverse(str, 0);

    cout << "The reversed string is: " << str << endl;
    return 0;
}
