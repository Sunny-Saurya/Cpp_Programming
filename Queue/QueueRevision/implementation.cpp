#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front : " << q.front() << endl;

    q.pop();
    
    cout << "Front : " << q.front() << endl;

    if(!q.empty()){
        cout << "Not Empty";
    }
    else{
        cout << "Empty";
    }

}