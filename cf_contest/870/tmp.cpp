#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using ll=long long;

int main(){
    fastio;
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

    // constexpr ll con=6;
    // ll m,n;cin>>m>>n;
    // vector<ll> p(n,0);for(ll &i:p)cin>>i;
    // vector<vector<ll>> r(m,vector<ll> (n));for(auto &v:r)for(auto &i:v)cin>>i;
    // vector<vector<bitset<con>>> bs(m,vector<bitset<con>> (n,0));
    // for(ll i=0;i<m;i++){
    //     vector<pair<ll,ll>> tmp(n);
    //     for(ll j=0;j<n;j++){
    //         tmp[j].first=r[i][j];
    //         tmp[j].second=j;
    //     }
    //     sort(tmp.begin(),tmp.end());
    //     for(ll j=1;j<n;j++){
    //         bs[i][tmp[j].second]|=bs[i][tmp[j-1].second];
    //         if( tmp[j].first>tmp[j-1].first){
    //             bs[i][tmp[j].second].set(tmp[j-1].second);
    //         }
    //     }
    //     // for(ll j=0;j<n;j++){
    //     //     cerr<<bs[i][j]<<"\t";
    //     // }
    //     // cerr<<"\n";
    // }

    // vector<pair<ll,ll>> tmp(n);
    // for(ll j=0;j<n;j++){
    //     tmp[j].first=r[0][j];
    //     tmp[j].second=j;
    // }
    // sort(tmp.begin(),tmp.end());
    // // cerr<<"\nnew:\n";
    // // for(int i=0;i<m;i++){
    // //     for(int j=0;j<n;j++){
    // //         cerr<<bs[i][tmp[j].second]<<"\t";
    // //     }
    // //     cerr<<"\n";
    // // }
    // vector<ll> dp(n,0);
    // dp[0]=p[tmp[0].second];
    // ll ans=dp[0];
    // for(ll i=1;i<n;i++){
    //     bitset<con> b=bs[0][tmp[i].second];
    //     // cerr<<tmp[i].second<<": "<<b<<"\n";
    //     for(ll j=1;j<m;j++){
    //         b&=bs[j][tmp[i].second];
    //     }
    //     // cerr<<tmp[i].second<<": "<<b<<"\n";
    //     for(ll j=0;j<i;j++){
    //         if(b.test(tmp[j].second)){
    //             dp[i]=max(dp[i],dp[j]);
    //         }
    //     }
    //     dp[i]+=p[tmp[i].second];
    //     ans=max(ans,dp[i]);
    // }
    // cout<<ans<<"\n";
}