#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n;
vector<vector<ll>> adj;
vector<ll> val;
vector<ll> sum;
vector<ll> par;

void dfs(ll nn, ll pp){
    for(ll ch:adj[nn]){
        if(ch!=pp){
            dfs(ch,nn);
            sum[nn]+=sum[ch];
            par[ch]=nn;
        }
    }
}

int main(){
    ll q;
    cin>>n>>q;
    adj.resize(n+1);
    sum.resize(n+1,0);
    par.resize(n+1,0);
    val.resize(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>val[i];
        sum[i]=val[i];
    }
    for(ll i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    dfs(1,0);
    for(ll i=0;i<q;i++){
        ll qt;cin>>qt;
        if(qt==1){
            ll u,x;cin>>u>>x;
            ll dif=x-val[u];
            val[u]=x;
            while(u!=0){
                sum[u] = sum[u]+dif;
                u = par[u]; 
            }
        }
        else{
            ll u;cin>>u;
            cout<<sum[u]<<endl;
        }
    }
}