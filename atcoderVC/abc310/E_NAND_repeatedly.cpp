#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;string s;cin>>s;
    vector<ll> dp[2];dp[0].resize(n,0);dp[1].resize(n,0);
    dp[0][0]=1;dp[1][0]=0;
    if(s[0]=='1')swap(dp[0][0],dp[1][0]);
    ll ans=dp[1][0];
    for(int i=1;i<n;i++){
        if(s[i]=='0'){
            dp[1][i]=dp[1][i-1]+dp[0][i-1];
            dp[0][i]=1;
        }
        else{
            dp[1][i]=dp[0][i-1]+1;
            dp[0][i]=dp[1][i-1];
        }
        ans+=dp[1][i];
    }
    cout<<ans<<endl;
    return 0;
}