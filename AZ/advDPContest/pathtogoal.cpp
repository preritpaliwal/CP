#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
ll n,x,y;
vector<vector<ll>> dp;
ll mod=1e9+7;
ll rec(ll idx,ll cur){
    if(idx==s.size())return (cur==y);
    if(dp[idx][cur]!=-1)return dp[idx][cur];
    if((cur==0 && s[idx]=='l') || (cur==n && s[idx]=='r'))return dp[idx][cur]=rec(idx+1,cur)%mod;
    // return dp[idx][cur]=(rec(idx+1,cur)+rec(idx+1,cur + ((s[idx]=='r')?1:-1)))%mod;
    dp[idx][cur]=(rec(idx+1,cur))%mod;
    dp[idx][cur]+=rec(idx+1,cur + ((s[idx]=='r')?1:-1));
    dp[idx][cur]%=mod;
    return dp[idx][cur];
}

void solve(){
    cin>>s>>n>>x>>y;
    dp.clear();
    dp.resize(s.size(),vector<ll> (n+1,-1));
    cout<<rec(0,x)<<endl;
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}