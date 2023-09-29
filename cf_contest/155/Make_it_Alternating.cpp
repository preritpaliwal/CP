#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
void solve(){
    string s;cin>>s;
    vector<ll> v;
    ll init=1;
    ll ops=0;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            init++;
        }
        else{
            if(init>1){
                v.push_back(init);
                ops+=init-1;
            }
            init=1;
        }
    }
    if(init>1){
        v.push_back(init);
        ops+=init-1;
    }
    cout<<ops<<" ";
    ll fact=1;
    for(int i=1;i<=ops;i++){
        fact*=i;
        fact%=mod;
    }
    for(int i:v){
        fact*=i;
        fact%=mod;
    }
    cout<<fact;
    cout<<endl;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}