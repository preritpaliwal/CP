#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
ll m,d,n;
string a,b;
ll dp[2001][2][2][2001][3];

ll sol(ll nn,ll til,ll tir, ll sum,ll odd){
    if(nn==n){
        if(sum==0)return 1;
        return 0;
    }
    if(dp[nn][til][tir][sum][odd]!=-1)return dp[nn][til][tir][sum][odd];
    int lo=0,hi=9;;
    if(til==1)lo=a[nn]-'0';
    if(tir==1)hi=b[nn]-'0';
    ll ans=0;
    for(int i=lo;i<=hi;i++){
        if(odd==2 && i!=d)continue;
        if((odd==0 || odd==1) && i==d)continue;
        int ntl=til,ntr=tir,nodd=odd;
        if(i!=a[nn]-'0')ntl=0;
        if(i!=b[nn]-'0')ntr=0;
        if(odd==0 && i!=d)nodd=2;
        if(odd==1)nodd=2;
        if(odd==2)nodd=1;
        ans += sol(nn+1,ntl,ntr,(sum*10+i)%m,nodd);
        ans%=mod;
    }
    return dp[nn][til][tir][sum][odd]=ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>m>>d;
    cin>>a>>b;
    n=a.size();
    cout<<sol(0,1,1,0,0)<<endl;
    // cerr<<" --------------------- \n";
    return;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}