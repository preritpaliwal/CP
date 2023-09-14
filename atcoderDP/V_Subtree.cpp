#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
vector<vector<ll>> adj;
vector<ll> indp;
vector<ll> outdp;
vector<vector<ll>> pre;
vector<vector<ll>> suf;

void indfs(ll nn,ll pp){
    indp[nn]=1;
    for(ll ch:adj[nn]){
        if(ch!=pp){
            indfs(ch,nn);
            indp[nn]=(indp[nn]*((1+indp[ch])%m))%m;
        }
    }
    pre[nn].resize(adj[nn].size(),1);
    suf[nn].resize(adj[nn].size(),1);
    for(int i=1;i<(int)adj[nn].size();i++){
        if(adj[nn][i-1]!=pp) pre[nn][i]=(pre[nn][i-1]*((1+indp[adj[nn][i-1]])%m))%m;
        else pre[nn][i]=pre[nn][i-1];
    }
    for(int i=(int)adj[nn].size()-2;i>=0;i--){
        if(adj[nn][i+1]!=pp) suf[nn][i]=(suf[nn][i+1]*((1+indp[adj[nn][i+1]])%m))%m;
        else suf[nn][i]=suf[nn][i+1];
    }
}

void outdfs(ll k,ll pp){
    int nn=-1;
    if(pp==0){
        nn=1;
        outdp[nn]=1;
    }
    else{
        nn=adj[pp][k];
        outdp[nn]=(1+(outdp[pp]*((pre[pp][k]*suf[pp][k])%m))%m)%m;
    }
    for(int i=0;i<(int)adj[nn].size();i++){
        if(adj[nn][i]!=pp){
            outdfs(i,nn);
        }
    }
}

int main(){
    cin>>n>>m;adj.resize(n+1);indp.resize(n+1);outdp.resize(n+1),pre.resize(n+1),suf.resize(n+1);
    for(ll i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    indfs(1,0);
    outdfs(1,0);
    for(ll i=1;i<=n;i++){
        cout<<(indp[i]*outdp[i])%m<<endl;
    }
}