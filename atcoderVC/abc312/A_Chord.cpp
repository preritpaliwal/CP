#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    string s;cin>>s;
    vector<string> v{
        "ACE","BDF","CEG","DFA","EGB","FAC","GBD"
    };
    for(string &s1:v){
        if(s1==s){cout<<"Yes\n";return 0;}
    }
    cout<<"No\n";
    return 0;
}