#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
int n;
vector<vector<int>> a;
vector<ll> dp;
ll solve(int mask,int k){
    if(k<0)return mask==0;
    if(dp[mask]!=-1)return dp[mask];
    ll ans=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i) && a[i][k]){
            ans=(ans+solve(mask^(1<<i),k-1))%mod;
        }
    }
    return dp[mask]=ans;
}
int main(){
    cin>>n;a.resize(n,vector<int> (n,0));for(auto &v:a)for(int &i:v)cin>>i;
    dp.resize(1<<n,0);
    // cout<<solve((1<<n)-1,n-1)<<endl;
    dp[0]=1;
    for(int mask=1;mask<(1<<n);mask++){
        int idx=-1;
        for(int i=0;i<n;i++)if(mask&(1<<i))idx++;
        for(int i=0;i<n;i++)if(mask&(1<<i) && a[i][idx])dp[mask]=(dp[mask]+dp[mask^(1<<i)])%mod;
    }
    cout<<dp[(1<<n)-1]<<endl;
}