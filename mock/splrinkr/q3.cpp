#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
vector<ll> a;
vector<vector<ll>> dp;

ll cal(ll l,ll r){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    if(l==r)return dp[l][r]=a[l];
    return dp[l][r]=max(cal(l+2,r)+a[l],cal(l+1,r-1)+a[r]);
}

void solve(){
    cin>>n;a.clear();a.resize(n);for(int i=0;i<n;i++)cin>>a[i];
    dp.clear();dp.resize(n,vector<ll> (n,-1));
    cout<<cal(0,n-1)<<endl;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}