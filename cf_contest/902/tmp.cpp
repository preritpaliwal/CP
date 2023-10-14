#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,m,k;cin>>n>>m>>k;
    map<ll,ll> mp;
    for(ll x=0;x<=m;x++){
        ll y=x;
        set<ll> s;
        s.insert(y);
        for(ll i=n;i>=1;i--){
            s.insert(y%i);
            y%=i;
        }
        // cerr<<"x= "<<x<<" "<<s.size()<<"\n";
        mp[s.size()]++;
    }
    cout<<mp[k]<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}