#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
int main(){
    int n;cin>>n;string s;cin>>s;
    vector<vector<ll>> dp(n,vector<ll> (n+1,0));
    dp[0][1]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=i+1;j++){
            if(s[i-1]=='>'){
                dp[i][j]=((dp[i-1][i]-dp[i-1][j-1])%mod+dp[i][j-1]+mod)%mod;
            }
            else{
                dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[n-1][n]<<endl;
}