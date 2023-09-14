#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp,h;
int n,m;
int sol(int k,int mask){
    if(k<0)return 0;
    if(dp[k][mask]!=-1)return dp[k][mask];
    int ans=sol(k-1,mask);
    for(int j=0;j<n;j++){
        if(mask&(1<<j))continue;
        ans=max(ans,h[k][j]+sol(k-1,mask|(1<<j)));
    }
    return dp[k][mask]=ans;
}

void solve(){
    cin>>n>>m;
    dp.clear();h.clear();
    dp.resize(m,vector<int> (1025,-1));
    h.resize(m, vector<int> (n,0));
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>h[i][j];
    int mask=0;
    cout<<sol(m-1,mask)<<endl;
}

int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}