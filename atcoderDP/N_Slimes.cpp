#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;vector<ll> a(n);for(ll &i:a)cin>>i;
    vector<vector<ll>> dp(n,vector<ll> (n,0));
    vector<ll> pre(n+1,0);
    for(int i=0;i<n;i++)pre[i+1]=pre[i]+a[i];
    for(int r=1;r<n;r++){
        for(int l=0;l+r<n;l++){
            ll ans=LLONG_MAX;
            for(int i=l;i<l+r;i++){
                ans=min(ans,dp[l][i]+dp[i+1][l+r]);
            }
            dp[l][l+r]=ans+pre[l+r+1]-pre[l];
        }
    }
    cout<<dp[0][n-1]<<endl;
}