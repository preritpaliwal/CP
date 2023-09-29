#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=998244353;
ll inv(ll k){
    ll p=mod-2;
    ll val=k;
    ll ans=1;
    while(p){
        if(p&1)ans=(ans*val)%mod;
        val=(val*val)%mod;p>>=1;
    }
    return ans;
}
int main(){
    vector<ll> pr((1<<11),0);
    pr[(1<<0)]=1;
    ll n;cin>>n;
    for(ll i=0;i<n;i++){
        ll a;cin>>a;
        ll pa=inv(a);
        vector<ll> tmp(1<<11,0);
        for(int s=0;s<(1<<11);s++){
            tmp[s]+=(((pr[s]*(a-min(a,10ll)))%mod)*pa)%mod;
            for(int j=1;j<=min(10ll,a);j++){
                tmp[(s|(s<<j))&((1<<11)-1)]+=(pr[s]*pa)%mod;
                tmp[s|(1<<j)]%=mod;
            }
        }
        pr=tmp;
    }
    ll ans=0;
    for(int i=0;i<(1<<10);i++){
        ans=(ans+pr[i|(1<<10)])%mod;
    }
    cout<<ans<<endl;
    return 0;
}