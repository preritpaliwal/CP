#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
vector<vector<vector<ll>>> dp;
ll solve(int i,int j,int mask){
    if(j==n){j=0;i++;
        if(i==m)return mask==0;
    }
    if(dp[i][j][mask]!=-1)return dp[i][j][mask];
    ll ans=0;
    if(mask&(1<<(n-1)))ans=solve(i,j+1,((mask<<1)&((1<<n)-1)));
    else if(mask&1 && j)ans=solve(i,j+1,(((mask<<1)|1)&((1<<n)-1)))+solve(i,j+1,(((mask^1)<<1)&((1<<n)-1)));
    else ans=solve(i,j+1,(((mask<<1)|1)&((1<<n)-1)));
    return dp[i][j][mask]=ans;
}

int main(){
    int t=1;cin>>t;
    while(t--){
        cin>>n>>m;
        if(n>m)swap(n,m);
        dp.clear();
        dp.resize(m,vector<vector<ll>> (n,vector<ll> (1<<n,-1)));
        cout<<solve(0,0,0)<<endl;;
    }
    return 0;
}