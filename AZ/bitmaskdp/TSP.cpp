#include <bits/stdc++.h>
using namespace std;

int n,dp[15][33000];
vector<vector<int>> adj;

int solve(int k,int mask){
    if(mask+1==(1<<n))return adj[k][0];
    if(dp[k][mask]!=-1)return dp[k][mask];
    int ans=1e9;
    for(int i=0;i<n;i++){
        if(adj[k][i]>0 && !(mask&(1<<(i)))){
            ans=min(ans,adj[k][i]+solve(i,mask|(1<<(i))));
        }
    }
    return dp[k][mask]=ans;
}

int main(){
    int t=1;cin>>t;
    while(t--){
        cin>>n;
        adj.clear();
        adj.resize(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;cin>>x;
                adj[i].push_back(x);
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<(1<<n);j++)dp[i][j]=-1;
        cout<<solve(0,1)<<endl;
    }
}