#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
vector<vector<int>> adj,lift;
vector<ll> sum,depth;
void dfs(int nn,int pp){
    depth[nn]=1+depth[pp];lift[nn][0]=pp;
    for(int i=1;i<20;i++)lift[nn][i]=lift[lift[nn][i-1]][i-1];
    for(int ch:adj[nn])if(ch!=pp)dfs(ch,nn);
}
int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    for(int i=19;i>=0;i--)if((depth[x]-depth[y])&(1<<i))x=lift[x][i];
    if(x==y)return x;
    for(int i=19;i>=0;i--)if(lift[x][i]!=lift[y][i])x=lift[x][i],y=lift[y][i];
    return lift[x][0];
}
void query(){
    int x,y,z;cin>>x>>y>>z;
    int l=lca(x,y);
    sum[x]+=z;sum[y]+=z;sum[l]-=z;sum[lift[l][0]]-=z;
}
void dfs2(int nn,int pp){
    for(int ch:adj[nn])if(ch!=pp)dfs2(ch,nn);
    sum[lift[nn][0]]+=sum[nn];
}
void solve(){
    cin>>n;
    adj.clear();adj.resize(n+1);
    lift.clear();lift.resize(n+1,vector<int> (20,0));
    sum.clear();sum.resize(n+1,0);
    depth.clear();depth.resize(n+1,-1);
    for(int i=1;i<n;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
    dfs(1,0);int q;cin>>q;while(q--)query();
    dfs2(1,0);for(int i=1;i<=n;i++)cout<<sum[i]<<" ";cout<<endl;
}
int main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}