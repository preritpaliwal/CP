#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int n,m;
vector<vector<int>> dp[1<<10];
int clip;
int solve(int mask,int i,int j){
    if(i==n){i=0;j++;if(j==m)return mask==0;}
    // cerr<<"call: "<<mask<<" "<<i<<" "<<j<<endl;
    if(dp[mask][i][j]!=-1)return dp[mask][i][j];
    int ans=0;
    if(mask&(1<<(n-1)))ans=solve((mask<<1)&clip,i+1,j);
    else if((mask&1) && i>0)ans=(0LL+solve(((mask^1)<<1)&clip,i+1,j)+solve(((mask<<1)|1)&clip,i+1,j))%mod;
    else ans=solve(((mask<<1)|1)&clip,i+1,j);
    // cerr<<"ret: "<<mask<<" "<<i<<" "<<j<<" :"<<dp[mask][i][j]<<endl;
    return dp[mask][i][j]=ans;
}
int main(){int mask=0;
    cin>>n>>m;
    clip=(1<<n)-1;
    for(int i=0;i<=clip;i++)dp[i].resize(n,vector<int> (m,-1));
    cout<<solve(0,0,0)<<endl;
}