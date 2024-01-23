#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;
    vector<ll> v(n+1);for(ll i=1;i<=n;i++)cin>>v[i];
    bool pos=true;
    for(ll i=3;i<min(4ll,n);i++){
        if(v[i]>v[i+1]){
            pos=false;
        }
    }
    for(ll i=5;i<min(8ll,n);i++){
        if(v[i]>v[i+1]){
            pos=false;
        }
    }
    for(ll i=9;i<min(n,16ll);i++){
        if(v[i]>v[i+1]){
            pos=false;
        }
    }
    for(ll i=17;i<n;i++){
        if(v[i]>v[i+1]){
            pos=false;
        }
    }
    cout<<((pos)?"YES\n":"NO\n");
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