#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,k;
vector<vector<ll>> adj,indp,outdp;

void indfs(ll nn, ll pp){
    indp[nn][0]=1;
    for(ll ch:adj[nn]){
        if(ch==pp)continue;
        indfs(ch,nn);
        for(ll i=1;i<=k;i++){
            indp[nn][i]+=indp[ch][i-1];
        }
    }
}

void outdfs(ll nn, ll pp){
    if(pp!=0){
        outdp[nn][1]=1;
        for(ll i=2;i<=k;i++){
			outdp[nn][i]=outdp[pp][i-1]+indp[pp][i-1]-indp[nn][i-2];            
        }
    }
    for(ll ch:adj[nn]){
        if(ch==pp)continue;
        outdfs(ch,nn);
    }
}

void solve(){
    cin>>n>>k;
    adj.clear();indp.clear();outdp.clear();
    adj.resize(n+1);indp.resize(n+1,vector<ll> (k+1,0));outdp.resize(n+1,vector<ll> (k+1,0));
    for(int i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    indfs(1,0);outdfs(1,0);
    ll ans=0;
    for(ll i=1;i<=n;i++)ans+=indp[i][k]+outdp[i][k];
    cout<<ans/2<<endl;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}