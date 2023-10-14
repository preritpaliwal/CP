#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;

void solve(){
    ll n;cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++)cin>>a[i];
    vector<ll> maxr(n+1,0);
    for(ll i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            maxr[i]=max(maxr[i],a[j]);
        }
    }
    sort(maxr.begin(),maxr.end());
    ll ans=0;
    ll two=1;
    for(int i=1;i<=n;i++){
        ans+=(maxr[i]*two)%mod;
        ans%=mod;
        two*=2;
        two%=mod;
    }
    cout<<ans<<endl;
}

int main(){
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}