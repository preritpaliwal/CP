#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n;
vector<ll> x;
vector<vector<ll>> dp[2];

ll solve(ll turn,ll l,ll r){
    if(dp[turn][l][r]!=-1)return dp[turn][l][r];
    if(l==r)return dp[turn][l][r]=x[l];
    return dp[turn][l][r]=max(x[l]-solve(turn^1,l+1,r),x[r]-solve(turn^1,l,r-1));
}

int main(){
    cin>>n;
    x.resize(n);
    dp[0].clear();dp[0].resize(n,vector<ll> (n,-1));
    dp[1].clear();dp[1].resize(n,vector<ll> (n,-1));
    ll sum=0;
    for(ll &i:x)cin>>i,sum+=i;
    cout<<(solve(0,0,n-1)+sum)/2<<endl;
}