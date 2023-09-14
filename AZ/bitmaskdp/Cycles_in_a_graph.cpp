#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;
vector<vector<ll>> adj;
vector<vector<ll>> dp;

ll solve(ll nn,ll par,ll pp,ll mask){
    if(dp[mask][nn]!=-1)return dp[mask][nn];
    ll ans=0;
    for(ll ch:adj[nn]){
        if(ch<pp)continue;
        if(ch==par)continue;
        if(ch==pp)ans+=1;
        if(mask&(1<<ch))continue;
        // cerr<<"call: "<<ch<<" "<<nn<<" "<<pp<<" "<<(mask|(1<<ch))<<endl;
        ans+=solve(ch,nn,pp,mask|(1<<ch));
        // cerr<<"ret: "<<ch<<" "<<nn<<" "<<pp<<" "<<(mask|(1<<ch))<<": "<<dp[mask|(1<<ch)][ch]<<endl;
    }
    return dp[mask][nn]=ans;
}

int main(){
    ll t=1;
    while(t--){
        cin>>n>>m;
        adj.clear();adj.resize(n);
        dp.clear();dp.resize((1<<n), vector<ll> (n,-1));
        for(ll i=0;i<m;i++){
            ll a,b;cin>>a>>b;
            adj[a-1].push_back(b-1);adj[b-1].push_back(a-1);
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            ans+=solve(i,i,i,0|(1<<i));
            // cerr<<ans<<" : "<<i<<endl;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}