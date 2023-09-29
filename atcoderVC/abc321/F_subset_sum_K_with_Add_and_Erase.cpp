#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=998244353;
int main(){
    int n,k;cin>>n>>k;
    vector<ll> dp(k+1,0);
    dp[0]=1;
    while(n--){
        char c;cin>>c;int a;cin>>a;
        if(c=='+'){
            for(int i=k;i>=a;i--){
                dp[i]+=dp[i-a];
                dp[i]%=mod;
            }
        }
        else{
            for(int i=a;i<=k;i++){
                dp[i]-=dp[i-a];
                dp[i]+=mod;
                dp[i]%=mod;
            }
        }
        // cerr<<endl<<c<<" "<<a<<" : "<<dp[k]<<endl;
        // for(int i=0;i<=k;i++){
        //     cerr<<dp[i]<<" ";
        // }
        cout<<dp[k]<<endl;
    }
}