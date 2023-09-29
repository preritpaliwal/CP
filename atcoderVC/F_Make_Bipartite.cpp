#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll n;cin>>n;vector<ll> a(n),b(n);for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)cin>>b[i];
    vector<vector<ll>> dp(n,vector<ll> (4,0));
    dp[0][0]=a[0];dp[0][1]=1e18;dp[0][2]=1e18;
    for(ll i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][0]+a[i]+b[i-1],dp[i-1][1]+a[i]);
        dp[i][1]=min(dp[i-1][0],dp[i-1][1]+b[i-1]);
        dp[i][2]=min(dp[i-1][2]+a[i]+b[i-1],dp[i-1][3]+a[i]);
        dp[i][3]=min(dp[i-1][2],dp[i-1][3]+b[i-1]);
    }
    cout<<min(min(dp[n-1][0],dp[n-1][3])+b[n-1],min(dp[n-1][1],dp[n-1][2]));
}