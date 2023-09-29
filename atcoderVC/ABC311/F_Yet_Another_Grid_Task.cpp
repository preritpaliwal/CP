#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
int main(){
    ll n,m;cin>>n>>m;
    vector<string> v(n);vector<vector<ll>> dp;
    dp.resize(n+1,vector<ll> (m,0));
    for(auto &s:v)cin>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='#'){
                if(i!=n-1){
                    v[i+1][j]='#';
                    if(j!=m-1)v[i+1][j+1]='#';
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][m-1]=1;
        if(i!=n && v[i][m-1]=='#')break;
    }
    for(int i=1;i<=n;i++)dp[i][m-1]=(dp[i][m-1]+dp[i-1][m-1])%mod;
    for(int j=m-2;j>=0;j--){
        for(int i=0;i<n;i++){
            dp[i][j]=dp[i+1][j+1];
            if(v[i][j]=='#'){
                break;
            }
        }
        if(v[n-1][j]!='#')dp[n][j]=dp[n][j+1];
        for(int i=1;i<=n;i++)dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
    }
    cout<<dp[n][0]<<endl;
    return 0;
}