#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;
#define MAXN 100005

int main(){
    fastio
    ll n,w;cin>>n>>w;
    vector<pair<ll,ll>> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i].first>>v[i].second;
    vector<ll> dp(MAXN,1e9+7);
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=MAXN-1-v[i].second;j>=0;j--){
            dp[j+v[i].second]=min(dp[j+v[i].second],dp[j]+v[i].first);
        }
        // for(ll j=0;j<110;j++){
        //     cerr<<dp[j]<<" ";
        // }
        // cerr<<endl<<endl<<endl;;
    }
    ll ans=0;
    for(ll i=0;i<MAXN;i++){
        if(dp[i]<=w)ans=i;
    }
    cout<<ans<<endl;
}