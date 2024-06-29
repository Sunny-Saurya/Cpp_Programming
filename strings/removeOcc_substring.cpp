// main str = daabcbaabcbc , part to delete = 'abc'
// become ---> dababc ---> daba

#include<iostream>
using namespace std;

string removeOcc(string str, string part)
{
    while (str.length() != '\0' && str.find(part) < str.length())
    {
        str.erase(str.find(part), part.length());
    }
    return str;
    
}
int main()
{
    string str;
    cout << "Enter any string : " << " ";
    getline(cin, str);

    string part;
    cout<< "Enter part you want to delete : " << " ";
    getline(cin, part);

    cout << "The final string is : " << removeOcc(str,part) << " ";
}