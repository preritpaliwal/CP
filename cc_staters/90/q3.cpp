#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n,m;
    cin>>m>>n;
    if(n>m){
        cout<<"NO\n";
        return;
    }
    vector<ll> v;
    ll tmp = m;
    v.push_back(tmp);
    while(tmp%2==0){
        tmp/=2;
        v.push_back(tmp);
    }
    for(int i = 0;i<v.size();i++){
        if(n>=v[i]){
            n-=v[i];
        }
    }
    if(n==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}