#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll=long long;
int mod=998244353;

int main(){
    fastio;
    ll n,a1,x,y,m,k;
    cin>>n>>a1>>x>>y>>m>>k;
    vector<ll> a(n+1);
    a[1]=a1;
    for(ll i=2;i<=n;i++)a[i]=((a[i-1]*x)%m+y)%m;
    vector<vector<ll>> b(k+1,vector<ll> (n+1,0));
    for(ll i=1;i<=n;i++)b[0][i]=(b[0][i-1]+a[i])%mod;
    for(ll _k=1;_k<=k;_k++){
        for(ll i=1;i<=n;i++){
            if(_k==1){
                b[_k][i]=(b[_k][i-1]+b[_k-1][i])%mod;
            }
            else{
                b[_k][i]=(b[_k][i-1]+b[_k-1][i-1])%mod;
            }
        }
    }
    ll ans=b[k][1];
    for(ll i=2;i<=n;i++){
        ans^=b[k][i]*i;
    }
    cout<<ans<<endl;
    return 0;
}