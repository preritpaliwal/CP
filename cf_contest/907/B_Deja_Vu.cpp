#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,q;cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> x(q);
    int minx=1e9;
    for(ll i=0;i<q;i++){
        cin>>x[i];
        if(x[i]<minx){
            minx=x[i];
            for(int i=0;i<n;i++){
                if(a[i]%(1<<minx)==0){
                    a[i]|=(1<<(minx-1));
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
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