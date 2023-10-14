#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
int main(){
    vector<ll> dp(7e3+1,0);
    dp[0]=1;
    int q;cin>>q;
    while(q--){
        int t,x;cin>>t>>x;
        if(t==0){
            for(int i=dp.size()-1;i>=x;i--){
                dp[i]+=dp[i-x];
                dp[i]%=mod;
            }
        }
        else if(t==1){
            for(int i=x;i<dp.size();i++){
                dp[i]-=dp[i-x];
                dp[i]=(dp[i]+mod)%mod;
            }
        }
        else{
            cout<<dp[x]<<" ";
        }
    }
}