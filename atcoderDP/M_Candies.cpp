#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
int main(){
    int n,k;cin>>n>>k;
    vector<int> a(n+1);for(int i=1;i<=n;i++)cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll> (k+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int j=1;j<=k;j++){
            if(j<=a[i]){
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
            }
            else{
                dp[i][j]=(dp[i][j-1]+(dp[i-1][j]-dp[i-1][j-a[i]-1]+mod)%mod)%mod;;
            }
        }
    }
    cout<<dp[n][k]<<endl;
}