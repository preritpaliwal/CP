#include <bits/stdc++.h>

using namespace std;

bool check1(string &f,int k,string &s){
    for(int i = 0;i<s.size();i++){
        if(f[(k+i)%f.size()]!=s[i]){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    string full = "FBFFBFFB";
    for(int i = 0;i<full.size();i++){
        if(check1(full,i,s)){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;

}

int  main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}