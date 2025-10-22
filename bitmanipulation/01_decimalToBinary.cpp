#include<bits/stdc++.h>
using namespace std;

string reverse(string res){
    string ans = "";
    for(int i = res.length() - 1; i >= 0; i--){
        ans += res[i];
    }
    return ans;
}

string decimalToBinary(int n){
    string res = "";

    while(n > 0){
        if(n % 2 == 1) res += '1';
        else res += '0';
        n = n/2;
    }
    string ans = reverse(res);
    return ans;
}

int main(){
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    string ans = " ";
    ans = decimalToBinary(n);
    
    for(auto i : ans){
        cout << i;
    }
    cout << endl;
}