#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<vector<ll>> dp,adj;
int main(){
    ll n,m;cin>>n>>m;
    dp.resize(n,vector<ll> (1<<n,0));adj.resize(n);
    for(ll i=0;i<m;i++){ll a,b,c;cin>>a>>b>>c;adj[a-1].push_back(b-1);adj[b-1].push_back(a-1);dp[a-1][(1<<(a-1)|1<<(b-1))]=c;dp[b-1][(1<<(a-1)|1<<(b-1))]=c;}
    for(ll mask=0;mask<(1<<n);mask++){
        for(ll i=0;i<n;i++){
            ll ans=0;
            if(mask&(1<<i)){
                for(ll j:adj[i]){
                    if(mask&(1<<j)){
                        ans=max(ans,dp[i][((1<<i) | (1<<j))]+dp[j][mask^(1<<i)]);
                    }
                }
            }
            dp[i][mask]=ans;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][(1<<n)-1]);
    }
    cout<<ans<<endl;
    return 0;
}