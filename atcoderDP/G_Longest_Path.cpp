#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;
ll n,m;
vector<vector<ll>> adj;
vector<ll> lp;

void dfs(int nn){
    if(lp[nn]!=-1){
        return;
    }
    ll len=0;
    for(ll n:adj[nn]){
        dfs(n);
        len=max(len,1+lp[n]);
    }
    lp[nn]=len;
}

int main(){
    fastio
    cin>>n>>m;
    adj.resize(n+1);
    lp.resize(n+1,-1);
    for(ll i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        dfs(i);
        ans=max(ans,lp[i]);
    }
    cout<<ans<<endl;
}