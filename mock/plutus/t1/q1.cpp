#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll> (m,0));
    for(auto &tmp:v)for(auto &i:tmp)cin>>i;
    vector<vector<ll>> dp(n,vector<ll> (m,1e9));
    dp[n-1][m-1]=0;
    for(ll i=n-2;i>=0;i--){
        if(i+v[i][m-1]<n){
            dp[i][m-1]=min(dp[i][m-1],1+dp[i+v[i][m-1]][m-1]);
        }
    }
    for(ll j=m-2;j>=0;j--){
        if(j+v[n-1][j]<m){
            dp[n-1][j]=min(dp[n-1][j],1+dp[n-1][j+v[n-1][j]]);
        }
    }
    for(ll i=n-2;i>=0;i--){
        for(ll j=m-2;j>=0;j--){
            if(j+v[i][j]<m){
                dp[i][j]=min(dp[i][j],1+dp[i][j+v[i][j]]);
            }
            if(i+v[i][j]<n){
                dp[i][j]=min(dp[i][j],1+dp[i+v[i][j]][j]);
            }
        }
    }
    cout<<(dp[0][0]>=1e9 ? -1:dp[0][0])<<"\n";
}