#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;

int main(){
    vector<ll> dp[2];
    dp[0].resize(1e6+1,0);
    dp[1].resize(1e6+1,0);
    dp[0][1]=1;
    dp[1][1]=1;
    for(int i=2;i< (int)dp[0].size();i++){
        dp[0][i]=(2*dp[0][i-1]+dp[1][i-1])%mod;
        dp[1][i]=(4*dp[1][i-1]+dp[0][i-1])%mod;
    }
    int t=1;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<(dp[0][n]+dp[1][n])%mod<<endl;
    }
}