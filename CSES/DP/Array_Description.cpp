#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;
ll n,m;
vector<int> v;
vector<vector<ll>> dp;

ll solve(int k,int last){
    if(k<0)return 1;
    if(dp[k][last]!=-1)return dp[k][last];
    ll ans=0;int lo=1,hi=m;
    if(k!=n-1){
        lo=max(lo,last-1);hi=min(hi,last+1);
    }
    if(v[k]==0)for(int i=lo;i<=hi;i++)ans=(ans+solve(k-1,i))%mod;
    else{
        if(v[k]<lo || v[k]>hi)ans=0;
        else ans=solve(k-1,v[k]);
    }
    return dp[k][last]=ans;
}

int main(){
    cin>>n>>m;
    v.clear();v.resize(n);
    dp.clear();dp.resize(n,vector<ll> (m+1,-1));
    for(int &i:v)cin>>i;
    cout<<solve(n-1,v[n-1])<<endl;
}