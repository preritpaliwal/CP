#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
vector<ll> par,sz,ans;
ll inv(ll n){
    ll p=mod-2,val=1,mul=n;
    while(p!=0){
        if(p&1)val=(val*mul)%mod;
        mul=(mul*mul)%mod;p>>=1;
    }
    return val;
}
ll find(ll n){
    if(n==par[n])return n;
    ll pp=par[n],tmp=find(pp);
    if(pp!=tmp)ans[n]=(ans[n]+ans[pp])%mod;
    return par[n]=tmp;
}
int main(){
    ll n;cin>>n;
    par.resize(n+1,0);sz.resize(n+1,0);
    for(ll i=1;i<=n;i++){par[i]=i;sz[i]=1;}
    ans.resize(n+1,0);
    for(ll i=1;i<n;i++){
        ll a,b;cin>>a>>b;a=find(a),b=find(b);
        ll t1=sz[a],t2=sz[b];ll inv12=inv((t1+t2)%mod);
        ans[a]+=(t1*inv12)%mod,ans[b]+=(t2*inv12)%mod;
        ans[b]%=mod;ans[a]=((ans[a]-ans[b])%mod+mod)%mod;
        par[a]=b;sz[b]+=sz[a];sz[b]%=mod;
    }
    for(int i=1;i<=n;i++){if(i!=find(i))ans[i]=(ans[i]+ans[par[i]])%mod;cout<<ans[i]<<" ";}
    return 0;
}