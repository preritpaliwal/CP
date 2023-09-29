#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
// vector<vector<ll>> adj;
vector<ll> dp;
ll solve(int mask){
    // cerr<<"call: "<<mask<<endl;
    if(dp[mask]!=-1){
        // cerr<<"ret: "<<mask<<" :"<<dp[mask]<<endl;
        return dp[mask];}
    int tmpmask=(mask-1)&mask;
    int bit=tmpmask^mask;
    // cerr<<mask<<" "<<tmpmask<<endl;
    ll ans=solve(tmpmask);
    // 1110, 0010, 1100
    for(int i=0;i<n;i++){
        if(tmpmask&(1<<i)){
            // cerr<<"here for mask: "<<mask<<" "<<i<<endl;
            ans=max(ans,solve(bit|(1<<i))+solve(tmpmask^(1<<i)));
        }
    }
    // cerr<<"ret-> "<<ans<<endl;
    return dp[mask]=ans;
}
int main(){
    cin>>n;dp.resize(1<<n,-1);dp[0]=0;
    for(int i=0;i<n;i++)dp[(1<<i)]=0;
    for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++){int b;cin>>b;dp[(1<<i)|(1<<j)]=b;}
    // for(int i=0;i<(1<<n);i++){
    //     cerr<<i<<":"<<dp[i]<<endl;
    // }
    cout<<solve((1<<n)-1)<<endl;;
}