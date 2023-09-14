#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;

int main(){
    fastio
    ll n,m;cin>>n>>m;
    vector<ll> s(m,0);
    for(ll i=0;i<m;i++)cin>>s[i];
    vector<vector<ll>> r(n,vector<ll> (m,0));
    for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>r[i][j];
    vector<pair<ll,ll>> r0;
    for(ll i=0;i<m;i++)r0.push_back({r[0][i],i});
    sort(r0.begin(),r0.end());
    vector<ll> dp(m,0);
    dp[0]=s[r0[0].second];
    ll ans=dp[0];
    for(ll i=1;i<m;i++){
        ll tmp=0;
        for(ll j=0;j<i;j++){
            bool isLess=true;
            for(ll k=0;k<n;k++){if(r[k][r0[j].second]>=r[k][r0[i].second]){isLess=false;break;}}
            if(isLess)tmp=max(tmp,dp[j]);
        }
        dp[i]=s[r0[i].second]+tmp;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}