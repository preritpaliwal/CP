#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main(){
    int n,x;cin>>n>>x;
    vector<int> c(n);
    for(int &i:c)cin>>i;
    vector<int> dp(x+1,0);
    dp[0]=1;
    // for(int i=0;i<=x;i++){
    //     for(int j=0;j<n;j++){
    //         if(i+c[j]<=x)dp[i+c[j]]=(dp[i+c[j]]+dp[i])%mod;
    //     }
    // }
    for(int ci:c){
        for(int i=ci;i<=x;i++){
            dp[i]=(dp[i]+dp[i-ci])%mod;
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}