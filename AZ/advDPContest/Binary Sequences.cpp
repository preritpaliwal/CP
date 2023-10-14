#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
vector<vector<ll>> dp;
void solve(){
    ll n,k;cin>>n>>k;
    dp.assign(n+1,vector<ll> (k+1,0));
    dp[1][1]=2;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            dp[i+1][1]=(dp[i+1][1]+dp[i][j])%mod;
            if(j!=k)dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
        }
    }
    ll ans=0;
    for(int i=0;i<=k;i++)ans=(ans+dp[n][i])%mod;
    cout<<ans<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}