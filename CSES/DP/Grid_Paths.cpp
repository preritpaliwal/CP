#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<vector<ll>> v(n,vector<ll> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            if(c=='.')v[i][j]=1;
        }
    }
    vector<vector<ll>> dp(n,vector<ll> (n,0));
    dp[0][0]=v[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==0)continue;
            if(j>0)dp[i][j]=(dp[i][j-1]+dp[i][j])%mod;
            if(i>0)dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}