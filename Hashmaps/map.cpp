#include<bits/stdc++.h>
using namespace std;

int main()
{
    // creation of map;

    map<string, int> m;

    // insertion

    //1
    pair<string, int> p = make_pair("sunny",3);
    m.insert(p);

    //2

    pair<string,int> pair2("kumar", 2);
    m.insert(pair2);

    //3
    m["iam"] = 1;

    // what will happen when we again insert the the same string --> it will update the value

    m["iam"] = 2;

    // searching

    cout << m["iam"] << endl;
    cout << m.at("sunny") << endl;

    // cout << m.at("unknowkey") << endl;

    cout  << m["unknownkey"] << endl; // it will create the entry of unknownkey and map with 0

    cout << m.at("unknownkey") << endl; // this will return 0. which is mapped earlier

    // size

    cout << m.size() << endl;

    // to check the presence

    cout << m.count("bro") << endl; // return 0 means -> not present

    cout << m.count("sunny") << endl;

    // to erase or delete something

    m.erase("sunny");
    cout << m.size() << endl;


    // interator

    for(auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    // interator2

    map<string, int> :: iterator it = m.begin();

    while (it != m.end())       
    {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    
    return 0;

}