#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
ll binpow(ll base,ll pow){
    ll ans=1;
    while(pow!=0){
        if(pow&1){
            ans*=(base);
        }
        base*=base;
        pow>>=1;
    }
    return ans;
}
void solve(){
    ll q;cin>>q;
    vector<ll> range(64,0);
    for(ll i=2;i<64;i++){
        ll l=1ll<<i;
        ll r=(1ll<<(i+1));
        ll base=i;
        ll start=base * log2(l)/log2(base);
        ll po = binpow(base,start+1);
        range[i]=(r-po)*(start+1)+start*(po-l);
        cerr<<range[i]<<"\n";
    }
    while(q--){
        ll l,r;cin>>l>>r;
        ll rl= log2(l),;
    }
    return;
}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        cerr<<t<<":\n";
        solve();
    }
    return 0;
}