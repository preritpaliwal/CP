#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> dp;
vector<ll> v;
ll solve(ll k,ll bot){
    if(dp[k]!=-1)return dp[k];
    ll ans=0;
    if(k%2==1){
        ans=max(solve(k),v[k]+solve(k-1));
    }

    return 
}

void solve(){
    ll n;cin>>n;v.resize(n);for(ll &i:v)cin>>i;
    dp.resize(n,-1);
    cout<<solve(n,v[n-1])<<endl;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}