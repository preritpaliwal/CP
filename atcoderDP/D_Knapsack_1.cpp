#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

int main(){
    fastio;
    ll n,w;cin>>n>>w;
    vector<pair<ll,ll>> v(n+1);
    for(ll i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    vector<ll> dp(w+1,0);
    for(ll i=1;i<=n;i++){
        for(int j=w;j>=0;j--){
            if(j+v[i].first<=w){
                dp[j+v[i].first]=max(dp[j+v[i].first],dp[j]+v[i].second);
            }
            // cerr<<dp[j]<<" ";
        }
        // cerr<<endl;
    }
    ll ans=0;
    for(ll i=1;i<=w;i++)ans=max(dp[i],ans);
    cout<<ans<<endl;
}