#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n,p;cin>>n>>p;
    vector<ll> a(n),b(n);
    for(ll &i:a)cin>>i;
    for(ll &i:b)cin>>i;
    multiset<pair<ll,ll>> s;
    for(ll i=0;i<n;i++){
        s.insert({b[i],a[i]});
    }
    s.insert({p,1e9});
    ll ans=p;
    ll cnt=1;
    while(cnt<n){
        auto it=s.begin();
        ans+=(it->first)*(min(it->second,n-cnt));
        cnt+=min(it->second,n-cnt);
        s.erase(it);
    }
    cout<<ans<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}