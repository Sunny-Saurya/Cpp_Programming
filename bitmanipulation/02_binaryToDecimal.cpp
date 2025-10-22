#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string str){
    int p1 = 1;
    int num = 0;

    for(int i= str.size()-1; i >= 0; i--){
        if(str[i] == '1'){
            num = num + p1;
        }
        p1 = p1*2;
    }
    return num;
}

int main(){
    string n;
    cout << "Enter the Binary String: ";
    cin >> n;
    int ans = binaryToDecimal(n);
    cout << ans << " ";
    cout << endl;
}