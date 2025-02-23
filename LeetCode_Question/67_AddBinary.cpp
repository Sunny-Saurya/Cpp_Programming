#include<bits/stdc++.h>
using namespace std;

string addBinary(string a , string b){
    int i = a.size() -1;
    int j = b.size() -1;
    int carry = 0;
    string result = "";

    while(i >= 0 || j >= 0 || carry){
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        result += (sum % 2) + '0';
        carry = sum / 2;
    }
    return result;
}

int main()
{
    cout << "Enter two binary numbers: ";
    string a, b;
    cin >> a >> b;

    cout << addBinary(a, b) << endl;

}