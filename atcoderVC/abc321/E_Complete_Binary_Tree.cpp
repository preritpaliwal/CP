#include <bits/stdc++.h>
using namespace std;
using ll=long long;


ll num(ll n,ll k,ll x){
    if(x<0)return 0;
    ll l=k,r=k;
    while(x--){
        if(l*2>n)return 0;
        l*=2;
        r=min(n,2*r+1);
    }
    return r-l+1;
}

void solve(){
    ll n,k,x;cin>>n>>k>>x;
    ll ans=num(n,k,x);
    ll nn=k;
    ll pp=nn>>1;
    ll cnt=1;
    while(pp){
        ans+=num(n,pp,x-cnt)-num(n,nn,x-cnt-1);
        nn>>=1;pp>>=1;
        cnt++;
    }
    cout<<ans<<endl;
    return ;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
