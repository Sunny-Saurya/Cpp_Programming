#include <iostream>
using namespace std;

int getLenght(char name[]) // not need of lenght
{
    int sum = 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        sum++;
    }
    return sum;
}

char isPalindrome(char ch[], int sum)
{
    int s = 0;
    int e = sum - 1;
    int flag = 0;
    while (s < e)
    {
        if (ch[s] != ch[e])
        {
            flag = 0;
            s++;
            e--;
        }
        else{
            flag = 1;
            s++;
            e--;
        }
    }
    if(flag == 0)
    {
        cout << "Not, palidrome string";
    }
    else{
        cout << "Yes, this is palidrome string ";
    }
}

int main()
{
    char ch[20];
    cout << "Enter string : " << " ";
    cin >> ch;
    int count = getLenght(ch); 
    isPalindrome(ch,count);

}