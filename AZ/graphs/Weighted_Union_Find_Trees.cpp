#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<ll> par,w,sz;

ll find(ll x){
    if(x==par[x])return x;
    ll y=find(par[x]);
    w[x]+=w[par[x]];
    return par[x]=y;
}

ll relate(ll x,ll y,ll z){
    ll px=find(x),py=find(y);
    if(px==py)return 0;
    if(sz[px]<sz[py]){
        par[px]=py;
        w[px]=w[y]-w[x]+z;
        sz[py]+=sz[px];
    }
    else{
        sz[px]+=sz[py];
        par[py]=px;
        w[py]=-(w[y]-w[x]+z);
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,q;cin>>n>>q;
    par.assign(n,0);w.assign(n,0);sz.assign(n,1);
    for(ll i=0;i<n;i++)par[i]=i;
    while(q--){
        ll t;cin>>t;
        if(t==0){
            ll x,y,z;cin>>x>>y>>z;
            relate(x,y,z);
        }
        else{
            ll x,y;cin>>x>>y;
            if(find(x)==find(y))cout<<w[x]-w[y]<<"\n";
            else cout<<"?\n";
        }
    }
}