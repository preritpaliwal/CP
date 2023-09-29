#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
vector<vector<ll>> adj;
vector<ll> sz,indp[2],outdp;
void indfs(ll nn,ll pp){
    indp[0][nn]=0;
    indp[1][nn]=0;
    sz[nn]=1;
    ll prev=0;
    for(ll ch:adj[nn]){
        if(ch!=pp){
            indfs(ch,nn);
            indp[0][nn]+=indp[1][ch];
            indp[1][nn]+=indp[1][ch]+prev*sz[ch];
            prev+=sz[ch];
            sz[nn]+=sz[ch];
        }
    }
}
void outdfs(ll nn,ll pp){
    if(nn==1)outdp[nn]=0;
    else outdp[nn]=outdp[pp]+indp[1][pp]-indp[1][nn]+(sz[pp]-1-sz[nn])*(n-sz[pp]-sz[nn]);
    for(ll ch:adj[nn])if(ch!=pp)outdfs(ch,nn);
}
int main(){
    cin>>n;adj.resize(n+1);for(ll i=1;i<n;i++){ll a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
    sz.resize(n+1,0);indp[0].resize(n+1);indp[1].resize(n+1);outdp.resize(n+1);
    indfs(1,0);outdfs(1,0);ll ans=0;
    for(ll i=1;i<=n;i++)ans+=(indp[0][i]+outdp[i]);
    cout<<ans/3<<endl;
}