#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n,x;cin>>n>>x;
    string s;cin>>s;
    vector<ll> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]= pre[i-1]+ (s[i-1]=='1');
        // cerr<<pre[i]<<"\n";
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        // cerr<<pre[i]<<": pre[i]\n";
        auto it=lower_bound(pre.begin(),pre.end(),pre[i]+x);
        ll l = max(i+1,(ll)(it-pre.begin()));
        // cerr<<l<<"\n";
        if(it==pre.end()){
            break;
        }
        // cerr<<i<<" ";
        ans+= (n+1-l);
    }
    cout<<ans<<"\n";
}